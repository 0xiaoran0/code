import random
import gymnasium as gym
import numpy as np
import collections
from torch import nn
from tqdm import tqdm
import torch
import torch.nn.functional as F


class ReplayBuffer:                      #经验池
    def __init__(self, capacity):
        self.buffer = collections.deque(maxlen=capacity)

    def add (self, state, action, reward, next_state, done):         #自动补齐的
        self.buffer.append((state, action, reward, next_state, done))

    def sample(self, batch_size):         #自动补齐的
        transitions = random.sample(self.buffer, batch_size)
        state, action, reward, next_state, done = zip(*transitions)           #解包
        return np.array(state), action, reward, np.array(next_state), done

    def size(self):
        return len(self.buffer)

class Qnet(torch.nn.Module):
    def __init__(self, state_size, action_size, hidden_size):
        super(Qnet, self).__init__()
        self.fc1 = torch.nn.Linear(state_size, hidden_size)
        self.fc2 = torch.nn.Linear(hidden_size, action_size)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        return self.fc2(x)


class DQN(nn.Module):
    def __init__(self, state_dim, hidden_dim, action_dim, lr, gamma, epsilon, target_update, device):
        super(DQN, self).__init__()
        self.action_dim = action_dim
        self.q_net = Qnet(state_dim, hidden_dim, self.action_dim).to(device)
        self.target_net = Qnet(state_dim, hidden_dim, self.action_dim).to(device)
        self.optimizer = torch.optim.Adam(self.q_net.parameters(), lr = lr)
        self.gamma = gamma
        self.epsilon = epsilon
        self.target_update = target_update
        self.count = 0
        self.device = device

    def take_action(self, state):
        if np.random.rand() < self.epsilon:
            action = random.randint(0, self.action_dim - 1)             #随机一个动作
        else:
            state = torch.tensor([state], dtype=torch.float).to(self.device)
            action = self.q_net(state).argmax().item()         #计算.选择最大.返回索引
        return action

    def update(self, transition_dict):
        state = torch.tensor(transition_dict['state'], dtype=torch.float).to(self.device)
        actions = torch.tensor(transition_dict['action'], dtype=torch.long).view(-1, 1).to(self.device)      #横向转纵向
        rewards = torch.tensor(transition_dict['reward'], dtype=torch.float).view(-1, 1).to(self.device)
        next_states = torch.tensor(transition_dict['next_state'], dtype=torch.float).to(self.device)
        dones = torch.tensor(transition_dict['done'], dtype=torch.float).view(-1, 1).to(self.device)
        q_values = self.q_net(state).gather(1, actions)

        max_next_q_values = self.target_q_net(next_states).max(1)[0].view(-1, 1)
        q_target = rewards + self.gamma * max_next_q_values * (1 - dones)
        dqn_loss = F.mse_loss(q_values, q_target)
        self.optimizer.zero_grad()
        dqn_loss.backward()
        self.optimizer.step()

        if self.count % self.target_update == 0:
            self.target_net.load_state_dict(self.q_net.state_dict())          #更新目标网络
        self.count += 1



lr = 2e-3                            #学习率
num_episode = 500                    #最大次数
hidden_dim = 128                     #隐藏层
gamma = 0.98                         #未来占比
epsilon = 0.01                       #贪婪策略
target_update = 10                   #更新频率
buffer_size = 10000                  #经验存储池容量
minimal_size = 500                   #网络更新时至少有 500 的容量
batch_size = 256                     #一次训练多少数据
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

env = gym.make('CartPole-v1')
random.seed(0)
np.random.seed(0)
env.reset(seed=0)
torch.manual_seed(0)
reply_buffer = ReplayBuffer(buffer_size)                   #创造经验池
state_dim = env.observation_space.shape[0]                 #状态空间的维度
action_dim = env.action_space.n
agent = DQN(state_dim, hidden_dim, action_dim, lr, gamma, epsilon, target_update, device)

return_list = []                         #回报列表
for i in range(10):
    with tqdm(total=int(num_episode/10), desc='Iteration %d' % i) as pbar:
        for i_episode in range(num_episode // 10):
            episode_return = 0
            state = env.reset(seed = 0)
            state = state[0]
            done = False
            while not done:
                action = agent.take_action(state)
                next_state, reward, done, truncated, _ = env.step(action)
                done = done or truncated
                reply_buffer.add(state, action, reward, next_state, done)
                state = next_state
                episode_return += reward

                if reply_buffer.size() > minimal_size:
                    b_s, b_a, b_r, b_ns, b_d = reply_buffer.sample(batch_size)
                    transition_dict = {
                        'state': b_s,
                        'action': b_a,
                        'next_state': b_ns,
                        'reward': b_r,
                        'done': b_d,
                    }
                    agent.optimizer.zero_grad()
                return_list.append(episode_return)