import matplotlib.pyplot as plt
import numpy as np
 
ypoints = np.array([1, 3, 4, 5, 8, 9, 6, 1, 3, 4, 5, 2, 4])
xpoints = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13])
plt.plot(xpoints, marker='o',c='darkviolet', linestyle='dotted', linewidth=3, label='Dark',ms=10)
plt.plot(ypoints, marker='o',c='violet', linestyle='dotted', linewidth=3, label='Data',ms=10)
 
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Line Chart')
plt.legend()

plt.show()