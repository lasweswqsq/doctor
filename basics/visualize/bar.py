import matplotlib.pyplot as plt
import numpy as np
 
np.random.seed(1)
x = np.arange(5)
y = np.random.randn(5)
 
fig, axes = plt.subplots(ncols=2, figsize=plt.figaspect(1./2))
 
vert_bars = axes[0].bar(x, y, color='lightblue', align='center')
horiz_bars = axes[1].barh(x, y, color='lightblue', align='center')
#在水平或者垂直方向上画线
axes[0].axhline(0, color='gray', linewidth=2)
axes[1].axvline(0, color='gray', linewidth=2)
plt.show()