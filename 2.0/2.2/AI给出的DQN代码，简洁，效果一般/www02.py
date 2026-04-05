import gymnasium as gym, torch
from torch import nn

NET_FILE = 'dqn_cartpole.pt'      # 与 train.py 同一路径
EPISODES = 30# 想看几局

net = nn.Sequential(
        nn.Linear(4, 128), nn.ReLU(),
        nn.Linear(128, 128), nn.ReLU(),
        nn.Linear(128, 2))
net.load_state_dict(torch.load(NET_FILE, map_location='cpu'))
net.eval()

env = gym.make('CartPole-v1')  # 关键：render_mode='human'
for ep in range(1, EPISODES+1):
    s, _ = env.reset()
    R = 0
    for t in range(1, 501):
        with torch.no_grad():
            a = int(net(torch.tensor(s, dtype=torch.float32)).argmax().item())
        s, r, d, tr, _ = env.step(a)
        R += r
        if d or tr:
            break
    print(f'Episode {ep}:  steps={t}  reward={R}')
env.close()
