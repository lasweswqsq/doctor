import matplotlib.pyplot as plt
import numpy as np
 
np.random.seed(196808012)
 
N = 50
x = np.random.rand(N)
y = np.random.rand(N)
colors = np.random.rand(N)
area = (30 * np.random.rand(N))**2  # 0 to 15 point radii
 
plt.scatter(x, y, s=area, c=colors, alpha=0.5)
plt.show()