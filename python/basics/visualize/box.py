import matplotlib.pyplot as plt
import numpy as np
 
# 利用随机数种子使每次生成的随机数相同
#np.random.seed(1023324)
collectn_1 = np.random.normal(100, 10, 200)
collectn_2 = np.random.normal(80, 30, 200)
collectn_3 = np.random.normal(90, 20, 200)
collectn_4 = np.random.normal(70, 25, 200)
data_to_plot = [collectn_1, collectn_2, collectn_3, collectn_4]
 
fig = plt.figure()
# 创建绘图区域
ax = fig.add_subplot(111)
# 创建箱型图
bp = ax.boxplot(data_to_plot)
plt.show()