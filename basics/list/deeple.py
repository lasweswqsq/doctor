import copy
x = [1, 2, [3, 4, [5, 6]]]
y= copy.deepcopy(x)
y[2][2][0] = 7
print(x)
print(y)