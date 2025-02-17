import matplotlib.pyplot as plt
import numpy as np
 
# 生成数据
x = np.arange(10)
y = np.random.rand(10)
 
# 创建柱状图
fig, ax = plt.subplots()
ax.bar(x, y)
 
# 设置x轴标签
ax.set_xticks(x)
ax.set_xticklabels(["标签" + str(i) for i in x], rotation=45)  # 旋转标签
 
plt.show()