L1 = [1,2,3]
L2 = [4,5,6]
L1.extend(L2)
L1.extend([[0,6], [4,5]])
print(L1)

#Output: [1, 2, 3, 4, 5, 6]

#Note:
#`@L1.extend([0,6], [4,5])  It will give an error as extend() method only takes one iterable argument.
print(L1)