# import gym, torch, random, numpy as np
# from collections import deque
# from torch import nn, optim
#
# BATCH, BUF, GAMMA, LR = 64, 50_000, 0.99, 1e-3
# MAX_EP = 300
#
# net = nn.Sequential(
#         nn.Linear(4, 128), nn.ReLU(),
#         nn.Linear(128, 128), nn.ReLU(),
#         nn.Linear(128, 2))
# tgt = nn.Sequential(
#         nn.Linear(4, 128), nn.ReLU(),
#         nn.Linear(128, 128), nn.ReLU(),
#         nn.Linear(128, 2))
# tgt.load_state_dict(net.state_dict())
# opt = optim.Adam(net.parameters(), lr=LR)
#
# buf = deque(maxlen=BUF)
# ε, ε_final = 1.0, 0.02
#
# env = gym.make('CartPole-v1')
# for ep in range(1, MAX_EP+1):
#     s, _ = env.reset()
#     for t in range(1, 501):
#         if random.random() < ε:
#             a = env.action_space.sample()
#         else:
#             with torch.no_grad():
#                 a = int(net(torch.tensor(s, dtype=torch.float32)).argmax())
#         s2, r, d, tr, _ = env.step(a)
#         buf.append((s, a, r, s2, d or tr))
#         s = s2
#         if len(buf) >= 1000:
#             b = random.sample(buf, BATCH)
#             ss, aa, rr, ss2, dd = map(np.array, zip(*b))
#             q = net(torch.tensor(ss, dtype=torch.float32)).gather(1, torch.tensor(aa).unsqueeze(1)).squeeze(1)
#             with torch.no_grad():
#                 y = torch.tensor(rr, dtype=torch.float32) + GAMMA * tgt(torch.tensor(ss2, dtype=torch.float32)).max(1)[0] * (~torch.tensor(dd))
#             loss = nn.functional.smooth_l1_loss(q, y)
#             opt.zero_grad(); loss.backward(); opt.step()
#         if d or tr:
#             break
#     ε = max(ε_final, ε - (1.0-ε_final)/300)
#     if ep % 10 == 0:
#         tgt.load_state_dict(net.state_dict())
#         print(f'Ep {ep:3d}  steps={t:3d}  ε={ε:.3f}')
#
# torch.save(net.state_dict(), 'dqn.pt')
# env.close()
#
#
#
#
# import gym, torch
# from torch import nn
#
# net = nn.Sequential(
#         nn.Linear(4, 128), nn.ReLU(),
#         nn.Linear(128, 128), nn.ReLU(),
#         nn.Linear(128, 2))
# net.load_state_dict(torch.load('dqn.pt'))
# net.eval()
#
# env = gym.make('CartPole-v1', render_mode='human')
# for ep in range(5):
#     s, _ = env.reset()
#     R = 0
#     for _ in range(500):
#         with torch.no_grad():
#             a = int(net(torch.tensor(s, dtype=torch.float32)).argmax())
#         s, r, d, tr, _ = env.step(a)
#         R += r
#         if d or tr:
#             break
#     print(f'Episode {ep+1}:  steps={_+1}  reward={R}')
# env.close()






















# import random
# import gymnasium as gym
# import numpy as np
# import collections
# from tqdm import tqdm
# import torch
# import torch.nn.functional as F
# import matplotlib.pyplot as plt
# import matplotlib
# matplotlib.use('TkAgg')
# import rl_utils
# import torch.nn.utils as utils
# from torch.optim.lr_scheduler import StepLR
#
# NET_FILE = 'dqn_cartpole.pt'      # 保存路径
# MAX_EP   = 30                    # 训练轮数
#
# class ReplayBuffer:
#     ''' 经验回放池 '''
#     def __init__(self, capacity):
#         self.buffer = collections.deque(maxlen=capacity)  # 队列,先进先出
#
#     def add(self, state, action, reward, next_state, done):  # 将数据加入buffer
#         self.buffer.append((state, action, reward, next_state, done))
#
#     def sample(self, batch_size):  # 从buffer中采样数据,数量为batch_size
#         transitions = random.sample(self.buffer, batch_size)
#         state, action, reward, next_state, done = zip(*transitions)
#         return np.array(state), action, reward, np.array(next_state), done
#
#     def size(self):  # 目前buffer中数据的数量
#         return len(self.buffer)
# class Qnet(torch.nn.Module):
#     ''' 只有一层隐藏层的Q网络 '''
#     def __init__(self, state_dim, hidden_dim, action_dim):
#         super(Qnet, self).__init__()
#         self.fc1 = torch.nn.Linear(state_dim, hidden_dim)
#         self.fc2 = torch.nn.Linear(hidden_dim, hidden_dim)
#         self.fc3 = torch.nn.Linear(hidden_dim, action_dim)
#
#     def forward(self, x):
#         x = F.relu(self.fc1(x))  # 隐藏层使用ReLU激活函数
#         x = F.relu(self.fc2(x))
#         return self.fc3(x)
# class DQN:
#     ''' DQN算法 '''
#     def __init__(self, state_dim, hidden_dim, action_dim, learning_rate, gamma,
#                  epsilon, target_update, device):
#         self.action_dim = action_dim
#         self.q_net = Qnet(state_dim, hidden_dim,
#                           self.action_dim).to(device)  # Q网络
#         # 目标网络
#         self.target_q_net = Qnet(state_dim, hidden_dim,
#                                  self.action_dim).to(device)
#         # 使用Adam优化器
#         self.optimizer = torch.optim.Adam(self.q_net.parameters(),
#                                           lr=learning_rate)
#         self.gamma = gamma  # 折扣因子
#         self.epsilon = epsilon  # epsilon-贪婪策略
#         self.target_update = target_update  # 目标网络更新频率
#         self.count = 0  # 计数器,记录更新次数
#         self.device = device
#         self.scheduler = StepLR(self.optimizer, step_size=100, gamma=0.9)
#
#     def take_action(self, state):  # epsilon-贪婪策略采取动作
#         if np.random.random() < self.epsilon:
#             action = np.random.randint(self.action_dim)
#         else:
#             state = torch.tensor([state], dtype=torch.float).to(self.device)
#             action = self.q_net(state).argmax().item()
#         return action
#
#     def update(self, transition_dict):
#         states = torch.tensor(transition_dict['states'],
#                               dtype=torch.float).to(self.device)
#         actions = torch.tensor(transition_dict['actions']).view(-1, 1).to(
#             self.device)
#         rewards = torch.tensor(transition_dict['rewards'],
#                                dtype=torch.float).view(-1, 1).to(self.device)
#         next_states = torch.tensor(transition_dict['next_states'],
#                                    dtype=torch.float).to(self.device)
#         dones = torch.tensor(transition_dict['dones'],
#                              dtype=torch.float).view(-1, 1).to(self.device)
#
#         q_values = self.q_net(states).gather(1, actions)  # Q值
#         # 下个状态的最大Q值
#         max_next_q_values = self.target_q_net(next_states).max(1)[0].view(
#             -1, 1)
#         q_targets = rewards + self.gamma * max_next_q_values * (1 - dones)  # TD误差目标
#         dqn_loss = torch.mean(F.mse_loss(q_values, q_targets))  # 均方误差损失函数
#         self.optimizer.zero_grad()  # PyTorch中默认梯度会累积,这里需要显式将梯度置为0
#         dqn_loss.backward()  # 反向传播更新参数
#         utils.clip_grad_norm_(self.q_net.parameters(), max_norm=5)
#         self.optimizer.step()
#
#         self.scheduler.step()
#
#         if self.count % self.target_update == 0:
#             self.target_q_net.load_state_dict(
#                 self.q_net.state_dict())  # 更新目标网络
#         self.count += 1
#
#     # 在 DQN 类中添加一个方法用于更新 epsilon
#     def update_epsilon(self, decay_rate):
#         self.epsilon = max(0.01, self.epsilon * decay_rate)
#
# class DenseRewardWrapper(gym.Wrapper):
#     def step(self, action):
#         obs, _, done, truncated, info = self.env.step(action)
#         x, vx, theta, omega = obs
#         reward = 1.0 \
#                - 0.5*(x/2.4)**2 \
#                - 0.5*(theta/0.209)**2 \
#                - 0.05*abs(vx) \
#                - 0.05*abs(omega)
#         if done and not truncated:
#             reward = -10
#         return obs, reward, done, truncated, info
#
# class NormalizeStateWrapper(gym.ObservationWrapper):
#     def observation(self, obs):
#         return obs / np.array([2.4, 3.0, 0.209, 3.0])
#
#
#
#
# lr = 5e-4
# num_episodes = 5000
# hidden_dim = 64
# gamma = 0.99
# epsilon = 0.9
# target_update = 50
# buffer_size = 20000
# minimal_size = 8000
# batch_size = 256
# device = torch.device("cuda") if torch.cuda.is_available() else torch.device(
#     "cpu")
#
# env_name = 'CartPole-v0'
# env = NormalizeStateWrapper(DenseRewardWrapper(gym.make(env_name)))
# random.seed(0)
# np.random.seed(0)
# env.reset(seed=0)
# torch.manual_seed(0)
# replay_buffer = ReplayBuffer(buffer_size)
# state_dim = env.observation_space.shape[0]
# action_dim = env.action_space.n
# agent = DQN(state_dim, hidden_dim, action_dim, lr, gamma, epsilon,
#             target_update, device)
#
# return_list = []
# for i in range(10):
#     with tqdm(total=int(num_episodes / 10), desc='Iteration %d' % i) as pbar:
#         for i_episode in range(int(num_episodes / 10)):
#             episode_return = 0
#             state = env.reset(seed=0)
#             state = state[0]
#             done = False
#             while not done:
#                 action = agent.take_action(state)
#                 next_state, reward, done, truncated, _ = env.step(action)
#                 done=done or truncated
#                 replay_buffer.add(state, action, reward, next_state, done)
#                 state = next_state
#                 episode_return += reward
#                 agent.update_epsilon(0.995)
#
#                 # 当buffer数据的数量超过一定值后,才进行Q网络训练
#                 if replay_buffer.size() > minimal_size:
#                     b_s, b_a, b_r, b_ns, b_d = replay_buffer.sample(batch_size)
#                     transition_dict = {
#                         'states': b_s,
#                         'actions': b_a,
#                         'next_states': b_ns,
#                         'rewards': b_r,
#                         'dones': b_d
#                     }
#                     agent.update(transition_dict)
#             return_list.append(episode_return)
#             if (i_episode + 1) % 10 == 0:
#                 pbar.set_postfix({
#                     'episode':
#                     '%d' % (num_episodes / 10 * i + i_episode + 1),
#                     'return':
#                     '%.3f' % np.mean(return_list[-10:])
#                 })
#             pbar.update(1)
# episodes_list = list(range(len(return_list)))
# plt.plot(episodes_list, return_list)
# plt.xlabel('Episodes')
# plt.ylabel('Returns')
# plt.title('DQN on {}'.format(env_name))
# plt.show()
#
# mv_return = rl_utils.moving_average(return_list, 9)
# plt.plot(episodes_list, mv_return)
# plt.xlabel('Episodes')
# plt.ylabel('Returns')
# plt.title('DQN on {}'.format(env_name))
#
# from torch import nn
#
# net = nn.Sequential(
#         nn.Linear(4, 128), nn.ReLU(),
#         nn.Linear(128, 128), nn.ReLU(),
#         nn.Linear(128, 2))
#
# torch.save(agent.q_net.state_dict(), NET_FILE)
# print('训练完成，权重已保存到', NET_FILE)
# env.close()









#!/usr/bin/env python3
# problem.py 改进版
import argparse, csv, random, gymnasium as gym, numpy as np, torch, torch.nn.functional as F
import matplotlib; matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
from tqdm import tqdm
from collections import deque

# ---------- 命令行参数 ----------
parser = argparse.ArgumentParser()
parser.add_argument('--lr', type=float, default=5e-4)
parser.add_argument('--episodes', type=int, default=2000)
parser.add_argument('--batch_size', type=int, default=256)
parser.add_argument('--buffer_size', type=int, default=20000)
parser.add_argument('--minimal_size', type=int, default=8000)
parser.add_argument('--hidden_dim', type=int, default=64)
parser.add_argument('--gamma', type=float, default=0.99)
parser.add_argument('--epsilon_start', type=float, default=0.9)
parser.add_argument('--epsilon_end', type=float, default=0.01)
parser.add_argument('--epsilon_decay', type=float, default=0.995)
parser.add_argument('--target_update', type=int, default=50)
parser.add_argument('--save_interval', type=int, default=100)
parser.add_argument('--seed', type=int, default=0)
parser.add_argument('--device', type=str, default='cuda' if torch.cuda.is_available() else 'cpu')
args = parser.parse_args()

# ---------- 工具 ----------
class ReplayBuffer:
    def __init__(self, capacity):
        self.buffer = deque(maxlen=capacity)
    def add(self, *t): self.buffer.append(t)
    def sample(self, batch_size):
        ts = random.sample(self.buffer, batch_size)
        return [np.array(x) for x in zip(*ts)]
    def size(self): return len(self.buffer)

def moving_average(lst, w=9):
    if len(lst) < w: return lst
    return [np.mean(lst[i:i+w]) for i in range(len(lst)-w+1)]

# ---------- 网络 ----------
class QNet(torch.nn.Module):
    def __init__(self, s_dim, h_dim, a_dim):
        super().__init__()
        self.fc1 = torch.nn.Linear(s_dim, h_dim)
        self.fc2 = torch.nn.Linear(h_dim, h_dim)
        self.fc3 = torch.nn.Linear(h_dim, a_dim)
    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return self.fc3(x)

# ---------- 算法 ----------
class DQN:
    def __init__(self, s_dim, h_dim, a_dim, lr, gamma, target_update, device):
        self.q_net = QNet(s_dim, h_dim, a_dim).to(device)
        self.tgt_net = QNet(s_dim, h_dim, a_dim).to(device)
        self.tgt_net.load_state_dict(self.q_net.state_dict())
        self.opt = torch.optim.Adam(self.q_net.parameters(), lr=lr)
        self.gamma, self.target_update, self.device = gamma, target_update, device
        self.cnt = 0
    def take_action(self, s, eps):
        if random.random() < eps:
            return random.randint(0, self.q_net.fc3.out_features-1)
        s = torch.tensor([s], dtype=torch.float32, device=self.device)
        return self.q_net(s).argmax().item()
    def update(self, b_s, b_a, b_r, b_ns, b_d):
        b_s = torch.tensor(b_s, dtype=torch.float32, device=self.device)
        b_a = torch.tensor(b_a, dtype=torch.long, device=self.device).unsqueeze(1)
        b_r = torch.tensor(b_r, dtype=torch.float32, device=self.device).unsqueeze(1)
        b_ns = torch.tensor(b_ns, dtype=torch.float32, device=self.device)
        b_d = torch.tensor(b_d, dtype=torch.float32, device=self.device).unsqueeze(1)

        q = self.q_net(b_s).gather(1, b_a)
        with torch.no_grad():
            max_q = self.tgt_net(b_ns).max(1)[0].unsqueeze(1)
            tgt = b_r + self.gamma * max_q * (1 - b_d)
        loss = F.mse_loss(q, tgt)
        self.opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_norm_(self.q_net.parameters(), 5)
        self.opt.step()
        if self.cnt % self.target_update == 0:
            self.tgt_net.load_state_dict(self.q_net.state_dict())
        self.cnt += 1
        return loss.item()

# ---------- 环境包装 ----------
class NormalizeStateWrapper(gym.ObservationWrapper):
    def observation(self, obs):
        return obs / np.array([2.4, 3.0, 0.209, 3.0], dtype=np.float32)

class DenseRewardWrapper(gym.Wrapper):
    def step(self, act):
        obs, _, done, truncated, info = self.env.step(act)
        x, vx, theta, omega = obs
        reward = 1.0 - 0.5*(x/2.4)**2 - 0.5*(theta/0.209)**2 - 0.05*abs(vx) - 0.05*abs(omega)
        if done and not truncated:
            reward = -10
        return obs, reward, done, truncated, info

# ---------- 主流程 ----------
def main():
    random.seed(args.seed); np.random.seed(args.seed); torch.manual_seed(args.seed)
    env_name = 'CartPole-v1'
    env = NormalizeStateWrapper(DenseRewardWrapper(gym.make(env_name)))
    s_dim = env.observation_space.shape[0]
    a_dim = env.action_space.n
    agent = DQN(s_dim, args.hidden_dim, a_dim, args.lr, args.gamma,
                args.target_update, args.device)
    buffer = ReplayBuffer(args.buffer_size)
    epsilon = args.epsilon_start
    return_list, loss_list = [], []

    with open('training_log.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['episode', 'return'])
        for ep in tqdm(range(args.episodes), desc='Training'):
            s, _ = env.reset(seed=args.seed+ep)
            ep_ret = 0
            while True:
                a = agent.take_action(s, epsilon)
                ns, r, d, tr, _ = env.step(a)
                done = d or tr
                buffer.add(s, a, r, ns, done)
                s = ns
                ep_ret += r
                if buffer.size() >= args.minimal_size:
                    b_s, b_a, b_r, b_ns, b_d = buffer.sample(args.batch_size)
                    loss = agent.update(b_s, b_a, b_r, b_ns, b_d)
                    loss_list.append(loss)
                if done: break
            epsilon = max(args.epsilon_end, epsilon * args.epsilon_decay)
            return_list.append(ep_ret)
            writer.writerow([ep, ep_ret])
            if (ep+1) % args.save_interval == 0:
                torch.save(agent.q_net.state_dict(), 'dqn_cartpole.pt')
                tqdm.write(f'Ep {ep+1:4d}  return={np.mean(return_list[-10:]):.3f}  eps={epsilon:.3f}')

    torch.save(agent.q_net.state_dict(), 'dqn_cartpole.pt')
    print('训练完成，权重已保存到 dqn_cartpole.pt')
    env.close()

    # ---------- 画图 ----------
    plt.figure(figsize=(12,5))
    plt.subplot(1,2,1); plt.plot(return_list); plt.title('Episode Return')
    plt.subplot(1,2,2); plt.plot(moving_average(return_list,9)); plt.title('Moving Avg Return')
    plt.tight_layout(); plt.show()

if __name__ == '__main__':
    main()