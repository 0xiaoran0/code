# import gymnasium as gym                          #PID可行
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
# state = env.reset()
# integral = 0.0
#
# while True:
#     # 检查 state 的长度是否至少为 4
#     if len(state) >= 4:
#         cart_position = state[0]  # 小车位置
#         cart_velocity = state[1]  # 小车速度
#         pole_angle = state[2]     # 摆的角度
#         pole_angular_velocity = state[3]  # 摆的角速度
#     else:
#         # 如果 state 长度不足，设置默认值或进行其他处理
#         cart_position = 0.0
#         cart_velocity = 0.0
#         pole_angle = 0.0
#         pole_angular_velocity = 0.0
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



import torch
#from torchrl.envs import GymEnv

# env = GymEnv("Pendulum-v1")                #载入环境
# reset = env.reset()
# print(reset)

# a = torch.tensor([1, 2])                   #张量的加减乘除
# print(a)
# b = torch.tensor([0.1, 0.2])
# print(b)
# print(a + b)
# print(a - b)
# print(a * b)
# print(a / b)
# print(a.shape)

a = torch.tensor([[1,2,3],[4,5,6],[7,8,9]])
print(torch.cuda.is_available())                           #测试让表格数据在GPU上运行不通过，不知道是不是因为显卡没开

# 创建一个需要计算梯度的张量
# x = torch.randn(2, 2, requires_grad=True)                   # 创建一个需要计算梯度的张量
# print(x)
# y = x + 2
# z = y * y * 3
# out = z.mean()                     #求所有张量的平均值
# print(out)

# x = torch.tensor([2.0], requires_grad=True)               #只有浮点型可以计算梯度
# y = x ** 2
# y.backward()
# print(x.grad)

