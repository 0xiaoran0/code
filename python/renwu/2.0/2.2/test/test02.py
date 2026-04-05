# import gymnasium as gym
# env = gym.make('CartPole-v1')
# for _ in range(1000):
#     env.reset()
#     for _ in range(100):
#         env.render()
#         env.step(env.action_space.sample())
# env.close()







# import gymnasium as gym
# import numpy as np
# import time
# import matplotlib.pyplot as plt
# import numpy as np
#
#
# class Q_Learning:
#
#     def __init__(self, env, alpha, gamma, epsilon, numberEpisodes, numberOfBins, lowerBounds, upperBounds):
#         import numpy as np
#
#         self.env = env
#         self.alpha = alpha
#         self.gamma = gamma
#         self.epsilon = epsilon
#         self.actionNumber = env.action_space.n
#         self.numberEpisodes = numberEpisodes
#         self.numberOfBins = numberOfBins
#         self.lowerBounds = lowerBounds
#         self.upperBounds = upperBounds
#
#         self.sumRewardsEpisode = []
#
#         self.Qmatrix = np.random.uniform(low=0, high=1, size=(
#         numberOfBins[0], numberOfBins[1], numberOfBins[2], numberOfBins[3], self.actionNumber))
#
#     def returnIndexState(self, state):
#         position = state[0]
#         velocity = state[1]
#         angle = state[2]
#         angularVelocity = state[3]
#
#         cartPositionBin = np.linspace(self.lowerBounds[0], self.upperBounds[0], self.numberOfBins[0])
#         cartVelocityBin = np.linspace(self.lowerBounds[1], self.upperBounds[1], self.numberOfBins[1])
#         poleAngleBin = np.linspace(self.lowerBounds[2], self.upperBounds[2], self.numberOfBins[2])
#         poleAngleVelocityBin = np.linspace(self.lowerBounds[3], self.upperBounds[3], self.numberOfBins[3])
#
#         indexPosition = np.maximum(np.digitize(state[0], cartPositionBin) - 1, 0)
#         indexVelocity = np.maximum(np.digitize(state[1], cartVelocityBin) - 1, 0)
#         indexAngle = np.maximum(np.digitize(state[2], poleAngleBin) - 1, 0)
#         indexAngularVelocity = np.maximum(np.digitize(state[3], poleAngleVelocityBin) - 1, 0)
#
#         return tuple([indexPosition, indexVelocity, indexAngle, indexAngularVelocity])
#
#     def selectAction(self, state, index):
#
#         if index < 500:
#             return np.random.choice(self.actionNumber)
#
#         randomNumber = np.random.random()
#
#         if index > 7000:
#             self.epsilon = 0.999 * self.epsilon
#
#         if randomNumber < self.epsilon:
#             return np.random.choice(self.actionNumber)
#
#         else:
#
#             return np.random.choice(np.where(
#                 self.Qmatrix[self.returnIndexState(state)] == np.max(self.Qmatrix[self.returnIndexState(state)]))[0])
#
#     def simulateEpisodes(self):
#         import numpy as np
#         for indexEpisode in range(self.numberEpisodes):
#
#             rewardsEpisode = []
#
#             (stateS, _) = self.env.reset()
#             stateS = list(stateS)
#
#             print("Simulating episode {}".format(indexEpisode))
#
#             terminalState = False
#             while not terminalState:
#
#                 stateSIndex = self.returnIndexState(stateS)
#
#                 actionA = self.selectAction(stateS, indexEpisode)
#
#                 (stateSprime, reward, terminalState, _, _) = self.env.step(actionA)
#
#                 rewardsEpisode.append(reward)
#
#                 stateSprime = list(stateSprime)
#
#                 stateSprimeIndex = self.returnIndexState(stateSprime)
#
#                 QmaxPrime = np.max(self.Qmatrix[stateSprimeIndex])
#
#                 if not terminalState:
#
#                     error = reward + self.gamma * QmaxPrime - self.Qmatrix[stateSIndex + (actionA,)]
#                     self.Qmatrix[stateSIndex + (actionA,)] = self.Qmatrix[stateSIndex + (actionA,)] + self.alpha * error
#                 else:
#                     error = reward - self.Qmatrix[stateSIndex + (actionA,)]
#                     self.Qmatrix[stateSIndex + (actionA,)] = self.Qmatrix[stateSIndex + (actionA,)] + self.alpha * error
#
#                 stateS = stateSprime
#
#             print("Sum of rewards {}".format(np.sum(rewardsEpisode)))
#             self.sumRewardsEpisode.append(np.sum(rewardsEpisode))
#
#     def simulateLearnedStrategy(self):
#         import gym
#         import time
#         env1 = gym.make('CartPole-v1', render_mode='human')
#         (currentState, _) = env1.reset()
#         env1.render()
#         timeSteps = 1000
#         obtainedRewards = []
#
#         for timeIndex in range(timeSteps):
#             print(timeIndex)
#             actionInStateS = np.random.choice(np.where(self.Qmatrix[self.returnIndexState(currentState)] == np.max(
#                 self.Qmatrix[self.returnIndexState(currentState)]))[0])
#             currentState, reward, terminated, truncated, info = env1.step(actionInStateS)
#             obtainedRewards.append(reward)
#             time.sleep(0.05)
#             if (terminated):
#                 time.sleep(1)
#                 break
#         return obtainedRewards, env1
#
#     def simulateRandomStrategy(self):
#         import gym
#         import time
#         import numpy as np
#         env2 = gym.make('CartPole-v1')
#         (currentState, _) = env2.reset()
#         env2.render()
#         episodeNumber = 100
#         timeSteps = 1000
#         sumRewardsEpisodes = []
#
#         for episodeIndex in range(episodeNumber):
#             rewardsSingleEpisode = []
#             initial_state = env2.reset()
#             print(episodeIndex)
#             for timeIndex in range(timeSteps):
#                 random_action = env2.action_space.sample()
#                 observation, reward, terminated, truncated, info = env2.step(random_action)
#                 rewardsSingleEpisode.append(reward)
#                 if (terminated):
#                     break
#             sumRewardsEpisodes.append(np.sum(rewardsSingleEpisode))
#         return sumRewardsEpisodes, env2
#
#
# ##########
# env = gym.make('CartPole-v1')
# (state, _) = env.reset()
#
# upperBounds = env.observation_space.high
# lowerBounds = env.observation_space.low
# cartVelocityMin = -3
# cartVelocityMax = 3
# poleAngleVelocityMin = -10
# poleAngleVelocityMax = 10
# upperBounds[1] = cartVelocityMax
# upperBounds[3] = poleAngleVelocityMax
# lowerBounds[1] = cartVelocityMin
# lowerBounds[3] = poleAngleVelocityMin
#
# numberOfBinsPosition = 30
# numberOfBinsVelocity = 30
# numberOfBinsAngle = 30
# numberOfBinsAngleVelocity = 30
# numberOfBins = [numberOfBinsPosition, numberOfBinsVelocity, numberOfBinsAngle, numberOfBinsAngleVelocity]
#
# alpha = 0.1
# gamma = 1
# epsilon = 0.2
# numberEpisodes = 150
#
# Q1 = Q_Learning(env, alpha, gamma, epsilon, numberEpisodes, numberOfBins, lowerBounds, upperBounds)
# Q1.simulateEpisodes()
# (obtainedRewardsOptimal, env1) = Q1.simulateLearnedStrategy()
#
# env1.close()
# np.sum(obtainedRewardsOptimal)
#
# (obtainedRewardsRandom, env2) = Q1.simulateRandomStrategy()
#
# (obtainedRewardsOptimal, env1) = Q1.simulateLearnedStrategy()







# import gymnasium as gym
# import numpy as np
# import time
# import matplotlib.pyplot as plt
#
# class Q_Learning:
#     def __init__(self, env, alpha, gamma, epsilon, numberEpisodes, numberOfBins, lowerBounds, upperBounds):
#         self.env = env
#         self.alpha = alpha
#         self.gamma = gamma
#         self.epsilon = epsilon
#         self.actionNumber = env.action_space.n
#         self.numberEpisodes = numberEpisodes
#         self.numberOfBins = numberOfBins
#         self.lowerBounds = lowerBounds
#         self.upperBounds = upperBounds
#         self.sumRewardsEpisode = []
#         self.Qmatrix = np.random.uniform(low=0, high=1, size=(
#             numberOfBins[0], numberOfBins[1], numberOfBins[2], numberOfBins[3], self.actionNumber))
#
#     def returnIndexState(self, state):
#         cartPositionBin = np.linspace(self.lowerBounds[0], self.upperBounds[0], self.numberOfBins[0])
#         cartVelocityBin = np.linspace(self.lowerBounds[1], self.upperBounds[1], self.numberOfBins[1])
#         poleAngleBin = np.linspace(self.lowerBounds[2], self.upperBounds[2], self.numberOfBins[2])
#         poleAngleVelocityBin = np.linspace(self.lowerBounds[3], self.upperBounds[3], self.numberOfBins[3])
#
#         indexPosition = np.maximum(np.digitize(state[0], cartPositionBin) - 1, 0)
#         indexVelocity = np.maximum(np.digitize(state[1], cartVelocityBin) - 1, 0)
#         indexAngle = np.maximum(np.digitize(state[2], poleAngleBin) - 1, 0)
#         indexAngularVelocity = np.maximum(np.digitize(state[3], poleAngleVelocityBin) - 1, 0)
#
#         return tuple([indexPosition, indexVelocity, indexAngle, indexAngularVelocity])
#
#     def selectAction(self, state, index):
#         if index < 500:
#             return np.random.choice(self.actionNumber)
#         if index > 7000:
#             self.epsilon = 0.999 * self.epsilon
#         if np.random.random() < self.epsilon:
#             return np.random.choice(self.actionNumber)
#         else:
#             return np.random.choice(np.where(
#                 self.Qmatrix[self.returnIndexState(state)] == np.max(self.Qmatrix[self.returnIndexState(state)]))[0])
#
#     def simulateEpisodes(self):
#         for indexEpisode in range(self.numberEpisodes):
#             rewardsEpisode = []
#             stateS, _ = self.env.reset()
#             stateS = list(stateS)
#             print("Simulating episode {}".format(indexEpisode))
#             terminalState = False
#             while not terminalState:
#                 stateSIndex = self.returnIndexState(stateS)
#                 actionA = self.selectAction(stateS, indexEpisode)
#                 stateSprime, reward, terminalState, _, _ = self.env.step(actionA)
#                 rewardsEpisode.append(reward)
#                 stateSprime = list(stateSprime)
#                 stateSprimeIndex = self.returnIndexState(stateSprime)
#                 QmaxPrime = np.max(self.Qmatrix[stateSprimeIndex])
#                 if not terminalState:
#                     error = reward + self.gamma * QmaxPrime - self.Qmatrix[stateSIndex + (actionA,)]
#                     self.Qmatrix[stateSIndex + (actionA,)] += self.alpha * error
#                 else:
#                     error = reward - self.Qmatrix[stateSIndex + (actionA,)]
#                     self.Qmatrix[stateSIndex + (actionA,)] += self.alpha * error
#                 stateS = stateSprime
#             print("Sum of rewards {}".format(np.sum(rewardsEpisode)))
#             self.sumRewardsEpisode.append(np.sum(rewardsEpisode))
#
#     def simulateLearnedStrategy(self):
#         env1 = gym.make('CartPole-v1', render_mode='human')
#         currentState, _ = env1.reset()
#         obtainedRewards = []
#         for timeIndex in range(1000):
#             actionInStateS = np.random.choice(np.where(
#                 self.Qmatrix[self.returnIndexState(currentState)] == np.max(
#                     self.Qmatrix[self.returnIndexState(currentState)]))[0])
#             currentState, reward, terminated, truncated, _ = env1.step(actionInStateS)
#             obtainedRewards.append(reward)
#             time.sleep(0.05)
#             if terminated:
#                 time.sleep(1)
#                 break
#         env1.close()
#         return obtainedRewards
#
#     def simulateRandomStrategy(self):
#         env2 = gym.make('CartPole-v1')
#         sumRewardsEpisodes = []
#         for episodeIndex in range(100):
#             rewardsSingleEpisode = []
#             state, _ = env2.reset()
#             for timeIndex in range(1000):
#                 random_action = env2.action_space.sample()
#                 observation, reward, terminated, truncated, info = env2.step(random_action)
#                 rewardsSingleEpisode.append(reward)
#                 if terminated:
#                     break
#             sumRewardsEpisodes.append(np.sum(rewardsSingleEpisode))
#         env2.close()
#         return sumRewardsEpisodes
#
# # ======================
# # 主程序
# # ======================
# env = gym.make('CartPole-v1')
# (state, _) = env.reset()
#
# upperBounds = env.observation_space.high
# lowerBounds = env.observation_space.low
# cartVelocityMin = -3
# cartVelocityMax = 3
# poleAngleVelocityMin = -10
# poleAngleVelocityMax = 10
# upperBounds[1] = cartVelocityMax
# upperBounds[3] = poleAngleVelocityMax
# lowerBounds[1] = cartVelocityMin
# lowerBounds[3] = poleAngleVelocityMin
#
# numberOfBins = [30, 30, 30, 30]
# alpha = 0.1
# gamma = 1
# epsilon = 0.2
# numberEpisodes = 10000
#
# Q1 = Q_Learning(env, alpha, gamma, epsilon, numberEpisodes, numberOfBins, lowerBounds, upperBounds)
# Q1.simulateEpisodes()
#
# # 测试学习策略
# obtainedRewardsOptimal = Q1.simulateLearnedStrategy()
#
# # 测试随机策略
# obtainedRewardsRandom = Q1.simulateRandomStrategy()
#
# # 绘制奖励曲线
# plt.plot(Q1.sumRewardsEpisode)
# plt.title("Training Rewards per Episode")
# plt.xlabel("Episode")
# plt.ylabel("Total Reward")
# plt.grid()
# plt.show()






# import gymnasium as gym
# from stable_baselines3 import DQN
# from stable_baselines3.common.monitor import Monitor
# from stable_baselines3.common.evaluation import evaluate_policy
#
# # 1. 创建环境：最大步数改成 1000（20秒）
# env = gym.make('CartPole-v1', max_episode_steps=1000)
# env = Monitor(env)
#
# # 2. 自定义网络结构 + 探索参数
# policy_kwargs = dict(net_arch=[256, 256])
#
# model = DQN(
#     'MlpPolicy',
#     env,
#     learning_rate=1e-3,
#     buffer_size=100_000,
#     learning_starts=10_000,
#     batch_size=64,
#     gamma=0.99,
#     target_update_interval=500,
#     exploration_fraction=0.3,
#     exploration_final_eps=0.01,
#     policy_kwargs=policy_kwargs,
#     verbose=1
# )
#
# # 3. 训练：100k 步
# model.learn(total_timesteps=100_000)
#
# # 4. 评估：跑 100 轮，看平均步数
# mean_reward, std_reward = evaluate_policy(model, env, n_eval_episodes=100)
# print(f"平均坚持步数: {mean_reward:.2f} ± {std_reward:.2f}")
# print(f"平均坚持秒数: {mean_reward * 0.02:.2f} 秒")
#
# # 5. 可视化一局
# obs, _ = env.reset()
# for step in range(1000):
#     env.render()
#     action, _ = model.predict(obs, deterministic=True)
#     obs, reward, done, truncated, info = env.step(action)
#     if done or truncated:
#         print(f"本轮坚持了 {step * 0.02:.2f} 秒")
#         break
# env.close()




# import gymnasium as gym                          #可以运行，但是没有窗口出现
# import numpy as np
#
# # 初始化环境
# env = gym.make('CartPole-v1')
#
# # 定义 PID 参数
# Kp, Ki, Kd = 1.5, 0.001, 0.1
#
# # 主循环
# total_reward = 0
# state = env.reset()
# integral = 0.0
#
# # 检查 state 的长度是否至少为 4
# if len(state) >= 4:
#     cart_position = state[0]  # 小车位置
#     cart_velocity = state[1]  # 小车速度
#     pole_angle = state[2]     # 摆的角度
#     pole_angular_velocity = state[3]  # 摆的角速度
# else:
#     # 如果 state 长度不足，设置默认值或进行其他处理
#     cart_position = 0.0
#     cart_velocity = 0.0
#     pole_angle = 0.0
#     pole_angular_velocity = 0.0
#
# # PID 控制器
# error = pole_angle  # 当前误差
# integral += error * 0.02  # 累积误差，假设 dt=0.02s
# derivative = pole_angular_velocity  # 变化率
#
# action_continuous = Kp * error + Ki * integral + Kd * derivative
# action_continuous = np.clip(action_continuous, -1, 1)  # 限制输出范围
#
# # 将连续动作转换为离散动作
# action = 1 if action_continuous > 0 else 0
#
# # 与环境交互
# # 在新版本的 OpenAI Gym 中，env.step(action) 返回的值可能不同
# # 使用 * 语法来适应不同的返回值数量
# step_result = env.step(action)
# if len(step_result) >= 4:
#     state, reward, done, _ = step_result[:4]
# else:
#     # 如果返回值数量不足，设置默认值或进行其他处理
#     state = step_result[0] if len(step_result) > 0 else state
#     reward = step_result[1] if len(step_result) > 1 else 0.0
#     done = step_result[2] if len(step_result) > 2 else False
#     _ = step_result[3] if len(step_result) > 3 else None
#
# total_reward += reward
#
# # 渲染环境
# env.render()
#
# # 检查是否结束
# if done:
#     print(f"Episode finished after {total_reward} steps.")
#
# # 关闭环境
# env.close()







# import gymnasium as gym                        #PID 可用
# import numpy as np
#
# # 初始化环境
# env = gym.make('CartPole-v1', render_mode="human")  # 确保环境支持渲染
#
# # 定义 PID 参数
# Kp, Ki, Kd = 1.5, 0.001, 0.1
#
# # 主循环
# total_reward = 0
# state, zero = env.reset()                    #需要两个数接收，不然第一次输入会出错
# integral = 0.0
#
# while True:
#     cart_position = state[0]  # 小车位置
#     cart_velocity = state[1]  # 小车速度
#     pole_angle = state[2]     # 摆的角度
#     pole_angular_velocity = state[3]  # 摆的角速度
#
#     # PID 控制器
#     error = pole_angle  # 当前误差
#     integral += error * 0.02  # 累积误差，假设 dt=0.02s
#     derivative = pole_angular_velocity  # 变化率
#
#     action_continuous = Kp * error + Ki * integral + Kd * derivative
#     action_continuous = np.clip(action_continuous, -1, 1)  # 限制输出范围
#
#     # 将连续动作转换为离散动作
#     action = 1 if action_continuous > 0 else 0
#
#     # 与环境交互
#     state, reward, done, _, _ = env.step(action)  # 获取新的状态、奖励和是否完成的标志
#     total_reward += reward
#
#     # 渲染环境
#     env.render()
#
#     # 检查是否结束
#     if done:
#         print(f"Episode finished after {total_reward} steps.")
#         break
#
# # 关闭环境
# env.close()





# import gym                                    #有BUG
# import torch
# import torch.nn as nn
# import torch.optim as optim
# from collections import deque
# import random
#
# # 定义自定义奖励函数
# def custom_reward(state, action):
#     x, x_dot, theta, theta_dot = state
#     reward = 1.0
#     reward -= abs(x) * 0.1  # 惩罚偏离中心
#     reward -= abs(theta) * 0.1  # 惩罚偏离竖直
#     return reward
#
# # 定义DQN网络
# class DQN(nn.Module):
#     def __init__(self):
#         super(DQN, self).__init__()
#         self.fc1 = nn.Linear(4, 128)
#         self.fc2 = nn.Linear(128, 2)
#
#     def forward(self, x):
#         x = torch.relu(self.fc1(x))
#         x = self.fc2(x)
#         return x
#
# # 定义经验回放缓冲区
# class ReplayBuffer:
#     def __init__(self, capacity):
#         self.buffer = deque(maxlen=capacity)
#
#     def add(self, state, action, reward, next_state, done):
#         self.buffer.append((state, action, reward, next_state, done))
#
#     def sample(self, batch_size):
#         batch = random.sample(self.buffer, batch_size)
#         states, actions, rewards, next_states, dones = zip(*batch)
#         return states, actions, rewards, next_states, dones
#
# # 初始化环境、网络和优化器
# env = gym.make("CartPole-v1")
# replay_buffer = ReplayBuffer(10000)
# policy_net = DQN()
# target_net = DQN()
# target_net.load_state_dict(policy_net.state_dict())
# optimizer = optim.Adam(policy_net.parameters(), lr=0.001)
# gamma = 0.99  # 折扣因子
# batch_size = 64
#
# # 训练循环
# for episode in range(1000):
#     state, _ = env.reset()
#     for t in range(200):
#         # 选择动作
#         state_tensor = torch.FloatTensor(state)
#         q_values = policy_net(state_tensor)
#         action = torch.argmax(q_values).item()
#
#         # 执行动作
#         next_state, reward, done, info = env.step(action)
#         reward = custom_reward(next_state, action)
#
#         # 添加到经验回放
#         replay_buffer.add(state, action, reward, next_state, done)
#
#         # 更新网络
#         if len(replay_buffer) > batch_size:
#             states, actions, rewards, next_states, dones = replay_buffer.sample(batch_size)
#             states_tensor = torch.FloatTensor(states)
#             actions_tensor = torch.LongTensor(actions)
#             rewards_tensor = torch.FloatTensor(rewards)
#             next_states_tensor = torch.FloatTensor(next_states)
#             dones_tensor = torch.FloatTensor(dones)
#
#             # 计算当前Q值
#             current_q = policy_net(states_tensor).gather(1, actions_tensor.unsqueeze(1)).squeeze()
#
#             # 计算目标Q值
#             next_q = target_net(next_states_tensor).max(1)[0]
#             target_q = rewards_tensor + gamma * next_q * (1 - dones_tensor)
#
#             # 更新网络
#             loss = nn.MSELoss()(current_q, target_q.detach())
#             optimizer.zero_grad()
#             loss.backward()
#             optimizer.step()
#
#         state = next_state
#         if done:
#             break
#
# # 保存训练好的模型
# torch.save(policy_net.state_dict(), "cartpole_dqn.pth")
#
# # 生成视频
# from gym.wrappers import RecordVideo
# env = RecordVideo(gym.make("CartPole-v1"), video_folder="videos", episode_trigger=lambda x: x % 100 == 0)
