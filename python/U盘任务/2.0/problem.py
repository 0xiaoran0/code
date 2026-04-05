import gymnasium as gym
import numpy as np

# 初始化环境
env = gym.make('CartPole-v1', render_mode="human")  # 确保环境支持渲染

state = env.reset()

while True:
    # 检查 state 的长度是否至少为 4
    if len(state) >= 4:
        cart_position = state[0]  # 小车位置
        cart_velocity = state[1]  # 小车速度
        pole_angle = state[2]     # 摆的角度
        pole_angular_velocity = state[3]  # 摆的角速度
    else:
        # 如果 state 长度不足，设置默认值或进行其他处理
        cart_position = 0.0
        cart_velocity = 0.0
        pole_angle = 0.0
        pole_angular_velocity = 0.0

    # 渲染环境
    env.render()

# 关闭环境
env.close()