# 导入需要的库
import numpy as np
import matplotlib.pyplot as plt

# ===================== 1. 用户输入数据 =====================
print("===== 最小二乘法线性拟合程序 =====")
# 输入变量名称
x_name = input("请输入自变量的名称（例如：时间/温度）：")
y_name = input("请输入因变量的名称（例如：速度/浓度）：")

# 输入数据数量
n = int(input("请输入数据点的总数量："))

# 输入自变量和因变量的值
x_data = []
y_data = []
print(f"\n请依次输入 {n} 个 {x_name} 的值：")
for i in range(n):
    x = float(input(f"第 {i+1} 个 {x_name}："))
    x_data.append(x)

print(f"\n请依次输入 {n} 个 {y_name} 的值：")
for i in range(n):
    y = float(input(f"第 {i+1} 个 {y_name}："))
    y_data.append(y)

# 转换为numpy数组方便计算
x = np.array(x_data)
y = np.array(y_data)

# ===================== 2. 最小二乘法计算 =====================
# 计算公式：y = kx + b
n = len(x)
# 计算求和项
sum_x = np.sum(x)
sum_y = np.sum(y)
sum_xy = np.sum(x * y)
sum_x2 = np.sum(x ** 2)

# 计算斜率 k 和截距 b
k = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x ** 2)
b = (sum_y - k * sum_x) / n

# 输出拟合结果
print("\n===== 拟合结果 =====")
print(f"拟合方程：{y_name} = {k:.4f} × {x_name} + {b:.4f}")
print(f"斜率 k = {k:.4f}")
print(f"截距 b = {b:.4f}")

# ===================== 3. 绘制拟合图像 =====================
plt.rcParams["font.family"] = ["SimHei", "WenQuanYi Micro Hei"]  # 支持中文显示
plt.figure(figsize=(8, 5))

# 绘制原始数据点
plt.scatter(x, y, color="red", label="原始数据", s=60, edgecolor="black")

# 绘制拟合直线
x_fit = np.linspace(min(x), max(x), 100)  # 生成平滑的x轴
y_fit = k * x_fit + b
plt.plot(x_fit, y_fit, color="blue", linewidth=2, label=f"拟合线：y={k:.2f}x+{b:.2f}")

# 设置图表标题和坐标轴名称
plt.title(f"{x_name} - {y_name} 最小二乘拟合曲线", fontsize=14, fontweight="bold")
plt.xlabel(x_name, fontsize=12)
plt.ylabel(y_name, fontsize=12)

# 显示网格和图例
plt.grid(alpha=0.3)
plt.legend(fontsize=11)

# 显示图片
plt.tight_layout()
plt.show()
