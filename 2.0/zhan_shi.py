import gymnasium as gym, torch, matplotlib.pyplot as plt
from torch import nn

NET_FILE = 'cartpole.pt'
EPISODES = 5

net = nn.Sequential(
        nn.Linear(4, 128), nn.ReLU(),
        nn.Linear(128, 2))
net.load_state_dict(torch.load(NET_FILE, map_location='cpu'))
net.eval()

env = gym.make('CartPole-v1', render_mode='rgb_array')  # 关键修改
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

    # 显示最后一帧
    img = env.render()
    plt.imshow(img)
    plt.title(f'Episode {ep}')
    plt.axis('off')
    plt.show()

env.close()


import os
# 打印Python当前工作目录
print("当前工作目录：", os.getcwd())
# 打印当前目录下的所有文件（确认是否有test.pt）
print("当前目录下的文件：", os.listdir())
