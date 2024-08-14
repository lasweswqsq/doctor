import matplotlib.pyplot as plt
import numpy as np
 
x = np.arange(10)
y = np.random.randn(10)
plt.scatter(x, y, color='red', marker='+')
plt.show()