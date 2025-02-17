import matplotlib.pyplot as plt
 
# 假设你已经有了数据
data = [10, 20, 30, 40, 50]
 
# 创建条形图
plt.bar(range(len(data)), data)
 
# 设置y轴的范围，确保包含所有的数据点
plt.ylim(0, max(data) + 5)  # 增加5是为了留出一些上间距
 
# 显示图表
plt.show()