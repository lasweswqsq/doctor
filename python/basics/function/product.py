def product(*a):
    sum = 0
    mul = 1
    for i in a: sum += i
    for i in a: mul *= i
    return (sum, mul)


# Testing the function
print(product(1, 2, 3, 4, 5)) # Output: (15, 120)

    