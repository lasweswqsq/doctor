from random import choice




class RandomWalk:
    def __init__(self, num_points=5000):

        self.num_points = num_points
        self.x_values = [0]
        self.y_values = [0]



    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x_direction = choice([-50,-40,-30,-20,-1,1,20,30,40,50])
            x_distance = choice([0, 1, 2, 3, 4,5])
            x_step = x_direction * x_distance

            y_direction = choice([-50,-40,-30,-20,-1,1,-1,20,30,40,50])
            y_distance = choice([0, 1, 2, 3, 4,5])
            y_step = y_direction * y_distance

            if x_step == 0 and y_step == 0:
                continue



            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            self.x_values.append(next_x)
            self.y_values.append(next_y)

import matplotlib.pyplot as plt

rw = RandomWalk(num_points=5000)
rw.fill_walk()

plt.style.use('classic')
fig, ax = plt.subplots(figsize=(10, 6))
point_numbers = range(rw.num_points)
#ax.scatter(rw.x_values, rw.y_values, linewidth=1, alpha=0.5,c=point_numbers,cmap=plt.cm.hsv,edgecolors='none',s=15)

ax.plot(rw.x_values, rw.y_values, linewidth=1 , alpha=0.5 , c='pink')

ax.scatter(0, 0, c='orange', edgecolors='none', s=100)
#重新绘制起点
ax.scatter(rw.x_values[2500], rw.y_values[2500], c='blue', edgecolors='none', s=100)
#重新绘制中间点
ax.scatter(rw.x_values[-1], rw.y_values[-1], c='green', edgecolors='none', s=100)
#重新绘制终点


ax.set_aspect('equal', adjustable='box')
ax.set_title("Random Walk")
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
plt.show()












'''
ax.scatter(0, 0, c='orange', edgecolors='none', s=100)
#重新绘制起点
ax.scatter(rw.x_values[2500], rw.y_values[2500], c='blue', edgecolors='none', s=100)
#重新绘制中间点
ax.scatter(rw.x_values[-1], rw.y_values[-1], c='green', edgecolors='none', s=100)
#重新绘制终点

#ax.scatter(rw.x_values, rw.y_values, s=1)
ax.set_aspect('equal', adjustable='box')
ax.set_title("Random Walk")
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
plt.show()
'''