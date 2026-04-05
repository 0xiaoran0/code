# import gymnasium as gym, torch
# from torch import nn
#
# NET_FILE = 'dqn_cartpole.pt'      # 与 train.py 同一路径
# EPISODES = 30                      # 想看几局
#
# net = nn.Sequential(
#         nn.Linear(4, 128), nn.ReLU(),
#         nn.Linear(128, 128), nn.ReLU(),
#         nn.Linear(128, 2))
# net.load_state_dict(torch.load(NET_FILE, map_location='cpu'))
# net.eval()
#
# env = gym.make('CartPole-v1', render_mode='human')  # 关键：render_mode='human'
# for ep in range(1, EPISODES+1):
#     s, _ = env.reset()
#     R = 0
#     for t in range(1, 501):
#         with torch.no_grad():
#             a = int(net(torch.tensor(s, dtype=torch.float32)).argmax().item())
#         s, r, d, tr, _ = env.step(a)
#         R += r
#         if d or tr:
#             break
#     print(f'Episode {ep}:  steps={t}  reward={R}')
# env.close()





import gymnasium as gym
import torch
import torch.nn.functional as F
import collections
import random
import numpy as np

NET_FILE = 'dqn_cartpole.pt'
EPISODES = 50
DEVICE = torch.device('cpu')

# 必须与训练脚本完全一致
class Qnet(torch.nn.Module):
    def __init__(self, state_dim=4, hidden_dim=64, action_dim=2):
        super(Qnet, self).__init__()
        self.fc1 = torch.nn.Linear(state_dim, hidden_dim)
        self.fc2 = torch.nn.Linear(hidden_dim, hidden_dim)
        self.fc3 = torch.nn.Linear(hidden_dim, action_dim)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return self.fc3(x)

# 构建网络并加载权重
net = Qnet().to(DEVICE)
net.load_state_dict(torch.load(NET_FILE, map_location=DEVICE))
net.eval()

# 可视化环境
env = gym.make('CartPole-v1', render_mode='human')
for ep in range(1, EPISODES + 1):
    state, _ = env.reset(seed=ep)
    total_reward = 0
    steps = 0
    done = False
    while not done:
        with torch.no_grad():
            state_t = torch.tensor(state, dtype=torch.float32).unsqueeze(0).to(DEVICE)
            action = int(net(state_t).argmax().item())
        state, reward, done, truncated, _ = env.step(action)
        total_reward += reward
        steps += 1
        done = done or truncated
    print(f'Episode {ep}: steps={steps}  reward={total_reward}')
env.close()


