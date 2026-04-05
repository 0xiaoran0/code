import gymnasium as gym

env = gym.make('CartPole-v1', max_episode_steps=1000)

observation, _ = env.reset()

kp, ki, kd = 1.5, 0.001, 0.1
total_reward = 0
integral = 0.0

while True:
    cart_position = observation[0]
    cart_velocity = observation[1]
    pole_angle = observation[2]
    pole_angular_velocity = observation[3]

    error = pole_angle
    integral += error * 0.1
    derivative = pole_angular_velocity
    action_continuous = kp * error + ki * integral + kd * derivative

    action = 1 if action_continuous > 0 else 0

    observation, reward, terminated, truncated, info = env.step(action)  # 获取新的状态、奖励和是否完成的标志
    total_reward += reward

    env.render()

    if terminated or truncated:
        print(f"Episode finished after {total_reward} steps.")
        break

env.close()