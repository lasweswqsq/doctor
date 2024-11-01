from random import choice
import matplotlib.pyplot as plt
class RandomWalk:
    def __init__(self, num_points=5000):

        self.num_points = num_points
        self.x_values = [0]
        self.y_values = [0]



    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x_direction = choice([1, -1])
            x_distance = choice([0, 1, 2, 3, 4,5])
            x_step = x_direction * x_distance

            y_direction = choice([1, -1])
            y_distance = choice([0, 1, 2, 3, 4,5])
            y_step = y_direction * y_distance

            if x_step == 0 and y_step == 0:
                continue



            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            self.x_values.append(next_x)
            self.y_values.append(next_y)

# 只要程序处于活动状态，就不断地模拟随机漫步
while True:
    # 创建一个RandomWalk实例
    rw = RandomWalk(100_000)
    rw.fill_walk()

    # 将所有的点都绘制出来
    plt.style.use('classic')
    fig, ax = plt.subplots(figsize=(10,5), dpi=128)
    point_numbers = range(rw.num_points)
    ax.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.hsv, edgecolors='none', s=1)

    # 突出起点和终点
    ax.scatter(0, 0, c='green', edgecolors='none', s=100)
    ax.scatter(rw.x_values[-1], rw.y_values[-1], c='black', edgecolors='none', s=100)

    # 隐藏坐标轴
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False) # 将坐标轴地可见性设置为False
    plt.show()

    keeping = input("Make another walk? (y/n):")
    if keeping == 'n':
        break
