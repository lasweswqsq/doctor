import matplotlib.pyplot as plt
import numpy as np

categories = ['Category A', 'Category B', 'Category C']
values1 = [5, 7, 9]
values2 = [6, 8, 10]

bar_width = 0.35
index = np.arange(len(categories))

plt.bar(index, values1, bar_width, label='Group 1')
plt.bar(index + bar_width, values2, bar_width, label='Group 2')

plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Clustered Bar Chart')
plt.xticks(index + bar_width / 2, categories)
plt.legend()
plt.show()
