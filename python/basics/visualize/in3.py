import matplotlib.pyplot as plt

x_values = range(1, 1001)
y_values = [x ** 2 for x in x_values]


fig, ax = plt.subplots()
# ax.scatter(x_values, y_values, c='red', s=10)  # 参数c为要设置使用的颜色
# ax.scatter(x_values, y_values, c=(0.3, 0.2, 0.5), s=10)  # RGB颜色模式设置
ax.scatter(x_values, y_values, c=y_values, cmap=plt.cm.hsv, s=10)  # 颜色映射，颜色渐变

# 设置图表标题并给坐标轴加上标签
plt.rcParams['font.sans-serif'] = ['SimHei']
ax.set_title("平方数", fontsize=24)
ax.set_xlabel("值", fontsize=14)
ax.set_ylabel("值的平方", fontsize=14)

# 设置刻度标记的大小
ax.tick_params(axis='both', which='major', labelsize=14)

# 设置每个坐标轴的取值范围
ax.axis([0, 1100, 0, 1100000])

plt.savefig('squares_plot.png', bbox_inches='tight')
# 第一个实参指定图表保存文件名，第二个实参指定将图表多余的空白区域裁剪掉，如果要保留图表周围多余的空白区域，只需省略第二个实参即可。
plt.show()