def deep_rev(L):
    L2 = []
    for e in L[::-1]:
        if type(e) == list:
            L2.append(deep_rev(e))
        else:
            L2.append(e)
    return L2

deep_rev([1, [2, 3], 4, [5, [6, 7], 8]])
# Output: [8, [7, 6], 5, [4, [3, 2], 1]]
print(deep_rev([1, [2, 3], 4, [5, [6, 7], 8]]))