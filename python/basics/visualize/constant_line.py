
import numpy as np
import matplotlib.pyplot as plt
 
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(15, 5))

x = np.linspace(0, np.pi)
y_sin = np.sin(x)
y_cos = np.cos(x)
 
ax1.plot(x, y_sin)
ax2.plot(x, y_sin, 'go--', linewidth=2, markersize=12)
ax3.plot(x, y_cos, color='red', marker='+', linestyle='dashed')

ax1.set_title('Sine Wave')
ax2.set_title('Sine Wave with markers')
ax3.set_title('Cosine Wave')

plt.show()