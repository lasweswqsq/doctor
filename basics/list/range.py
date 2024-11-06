range(4) #→ kind of like tuple (0,1,2,3)
range(2,9,2) #→ kind of like tuple (2,4,6,8)
L = [1,2,3,4]
for i in range(len(L)):
    L.append(i)
print(L)
'''
1st
time: L is [1, 2, 3, 4, 0]
2nd time: L is [1, 2, 3, 4, 0, 1]
3rd time: L is [1, 2, 3, 4, 0, 1, 2]
4th time: L is [1, 2, 3, 4, 0, 1, 2, 3]
'''