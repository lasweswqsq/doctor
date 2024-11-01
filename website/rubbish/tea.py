import matplotlib.pyplot as plt
# 示例数据
x = [1, 2, 3, 4, 5]
y = [10, 20, 25, 30, 35]
# 绘图
plt.plot(x, y)
plt.xlabel('x轴标签')  # 修正引号
plt.ylabel('Y轴标签')
plt.title('图表标题')  # 修正引号
# 手动调整边距
plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.2)
# 显示图表
plt.show()