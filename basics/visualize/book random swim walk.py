from random import choice
class RandomWalk:
    def __init__(self, num_points=5000):

        self.num_points = num_points
        self.x_values = [0]
        self.y_values = [0]



    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x_direction = choice([1, -1])
            x_distance = choice([0, 1, 2, 3, 4])
            x_step = x_direction * x_distance

            y_direction = choice([1, -1])
            y_distance = choice([0, 1, 2, 3, 4])
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
ax.scatter(rw.x_values, rw.y_values, linewidth=1, alpha=0.5,c=point_numbers,cmap=plt.cm.plasma,edgecolors='none',s=15)


#ax.scatter(rw.x_values, rw.y_values, s=1)
ax.set_aspect('equal', adjustable='box')
ax.set_title("Random Walk")
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
plt.show()