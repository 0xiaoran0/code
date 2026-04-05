# 导入核心库
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# ===================== 全局设置 =====================
plt.rcParams['font.sans-serif'] = ['DejaVu Sans']  # Linux系统字体（解决中文乱码）
plt.rcParams['axes.unicode_minus'] = False

# ✅ 修复点：直接读取本地CSV文件，不联网，100%成功
df = pd.read_csv('titanic.csv')

# ===================== 练习1：柱状图 - 不同舱位平均年龄 =====================
avg_age = df.groupby('class')['age'].mean()
plt.figure(figsize=(7, 5))
avg_age.plot(kind='bar', color='cornflowerblue', edgecolor='black')
plt.title('Average Age by Passenger Class', fontsize=12)
plt.xlabel('Class', fontsize=10)
plt.ylabel('Average Age', fontsize=10)
plt.xticks(rotation=0)
plt.tight_layout()
plt.show()

# ===================== 练习2：直方图 - 乘客年龄分布 =====================
age_clean = df['age'].dropna()
plt.figure(figsize=(8, 5))
plt.hist(age_clean, bins=20, color='lightgreen', edgecolor='black', alpha=0.7)
plt.title('Age Distribution of Passengers', fontsize=12)
plt.xlabel('Age', fontsize=10)
plt.ylabel('Count', fontsize=10)
plt.grid(axis='y', alpha=0.3)
plt.show()

# ===================== 练习3：散点图 - 年龄与票价的关系 =====================
scatter_data = df[['age', 'fare']].dropna()
plt.figure(figsize=(8, 5))
plt.scatter(scatter_data['age'], scatter_data['fare'], color='orange', alpha=0.6, s=30)
plt.title('Age vs Fare', fontsize=12)
plt.xlabel('Age', fontsize=10)
plt.ylabel('Fare', fontsize=10)
plt.grid(alpha=0.3)
plt.show()

# ===================== 练习4：箱线图 - 不同性别票价分布 =====================
plt.figure(figsize=(7, 5))
sns.boxplot(x='sex', y='fare', data=df, palette='Set2')
plt.title('Fare Distribution by Sex', fontsize=12)
plt.xlabel('Sex', fontsize=10)
plt.ylabel('Fare', fontsize=10)
plt.show()

# ===================== 练习5：综合柱状图 - 舱位+性别生还率 =====================
survival = df.groupby(['class', 'sex'])['survived'].mean().reset_index()
survival['Group'] = survival['class'].astype(str) + '-' + survival['sex']

plt.figure(figsize=(10, 5))
plt.bar(survival['Group'], survival['survived'], color=['lightpink', 'lightblue']*3, edgecolor='black')
plt.title('Survival Rate by Class & Sex', fontsize=12)
plt.xlabel('Class-Sex', fontsize=10)
plt.ylabel('Survival Rate', fontsize=10)
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
