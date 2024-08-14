import matplotlib.pyplot as plt

plt.style.use('ggplot')
x=12
y=13
fig, ax = plt.subplots()
ax.scatter(2, 4, s=200)
#scatter 的参数x表示x轴坐标，这里设置为2
#scatter 的参数y表示y轴坐标，这里设置为4
#scatter 的参数s表示点的大小，这里设置为200
#scatter 的参数c表示点的颜色，这里设置为默认值
#scatter 的参数marker表示点的形状，这里设置为默认值



ax.scatter(x, y, s=200, c='pink', marker='*')
#scatter 的参数x表示x轴坐标，这里设置为12
#scatter 的参数y表示y轴坐标，这里设置为13
#scatter 的参数s表示点的大小，这里设置为200
#scatter 的参数c表示点的颜色，这里设置为pink
#scatter 的参数marker表示点的形状，这里设置为*



ax.grid(True)
ax.set_aspect('equal')
ax.set_xlim(0, 20)
ax.set_ylim(0, 20)
ax.set_xlabel('X-axis', fontsize=19)
ax.set_ylabel('Y-axis')
ax.set_title('Scatter Plot')

plt.show()