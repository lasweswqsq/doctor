import tracemalloc

tracemalloc.start()
# 记录调用内存的时间
# 代码中分配内存的地方
x = [1, 2, 3]
y = [4, 5, 6]
z = x + y

tracemalloc.stop()

stats = tracemalloc.get_stats()
print(stats)

