import numpy as np
import matplotlib.pyplot as plt
 
"""
np.linspace()在指定的大间隔内[-4.0,4.0]，返回固定间隔100个数据
"""
x = np.linspace(-4.0, 4.0, 100)
y = np.linspace(-4.0, 4.0, 100)
 
"""
np.meshgrid()两个坐标轴上的点在平面上画格,产生一个以向量x为行，向量y为列的矩
"""
X, Y = np.meshgrid(x, y)
 
# 定义Z与X,Y之间的关系,即原方程x²+y²=r²
Z = np.sqrt(X ** 2 + Y ** 2)
 
fig, axes = plt.subplots(1, 2, figsize=(16, 9))
 
axes[0].contour(X, Y, Z, alpha=0.75, cmap=plt.cm.hot)
 
cp = axes[1].contourf(X, Y, Z, cmap=plt.cm.hot)
 
fig.colorbar(cp)
plt.show()