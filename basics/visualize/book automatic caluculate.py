import matplotlib.pyplot as plt

x_values = range(1,1000)
y_values = [x**2 for x in x_values]
x_label = "X-axis"
y_label = "Y-axis"
title = "Square Function"

fig, ax = plt.subplots()
plt.xlabel(x_label)
plt.ylabel(y_label)
plt.title(title)    
ax.axis([0, 1000, 0, 1000000])
ax.ticklabel_format(useOffset=False, style='sci')
ax.scatter(x_values, y_values,c=y_values,s=10,cmap=plt.cm.plasma)

#c（color） 是颜色，s （size）是大小
#cmap （color map）是色彩映射，Blues 是蓝色，s 是大小 plasma 是柔和的颜色
plt.plot(x_values, y_values)
plt.show()