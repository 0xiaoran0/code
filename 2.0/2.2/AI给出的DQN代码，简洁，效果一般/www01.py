import gymnasium as gym, torch, random, numpy as np, os
from collections import deque
from torch import nn, optim

NET_FILE = 'dqn_cartpole.pt'      # 保存路径
MAX_EP   = 1000                    # 训练轮数

net = nn.Sequential(
        nn.Linear(4, 128), nn.ReLU(),
        nn.Linear(128, 128), nn.ReLU(),
        nn.Linear(128, 2))
tgt = nn.Sequential(
        nn.Linear(4, 128), nn.ReLU(),
        nn.Linear(128, 128), nn.ReLU(),
        nn.Linear(128, 2))
tgt.load_state_dict(net.state_dict())
opt = optim.Adam(net.parameters(), lr=1e-3)

buf = deque(maxlen=50_000)
ε = 1.0

env = gym.make('CartPole-v1')          # 不加 render_mode
for ep in range(1, MAX_EP+1):
    s, _ = env.reset()
    for t in range(1, 501):
        a = env.action_space.sample() if random.random() < ε else \
            int(net(torch.tensor(s, dtype=torch.float32)).argmax().item())
        s2, r, d, tr, _ = env.step(a)
        buf.append((s, a, r, s2, d or tr))
        s = s2
        if len(buf) >= 1000:
            b = random.sample(buf, 64)
            ss, aa, rr, ss2, dd = map(np.array, zip(*b))
            q = net(torch.tensor(ss, dtype=torch.float32)).gather(1, torch.tensor(aa).unsqueeze(1)).squeeze(1)
            with torch.no_grad():
                y = torch.tensor(rr, dtype=torch.float32) + 0.99 * \
                    tgt(torch.tensor(ss2, dtype=torch.float32)).max(1)[0] * (~torch.tensor(dd))
            nn.functional.smooth_l1_loss(q, y).backward()
            opt.step(); opt.zero_grad()
        if d or tr:
            break
    ε = max(0.02, ε - 0.98/300)
    if ep % 10 == 0:
        tgt.load_state_dict(net.state_dict())
        print(f'Ep {ep:3d}  steps={t:3d}  ε={ε:.3f}')

torch.save(net.state_dict(), NET_FILE)
print('训练完成，权重已保存到', NET_FILE)
env.close()
