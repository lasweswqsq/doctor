import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
 
x = np.arange(5)
y1 = np.array([10, 8, 7, 11, 13])
bar_width = 0.3
plt.bar(x, y1, tick_label=['a', 'b', 'c', 'd', 'e'], width=bar_width)
 
# 使用 Seaborn 库中的 despine() 函数去除轴线
sns.despine()
 
plt.show()