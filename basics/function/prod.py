def make_prod(a):
    def g(b):
        return a*b
    return g

# Example usage
double = make_prod(2)
triple = make_prod(3)
print(double(5)) # Output: 10
print(triple(5)) # Output: 15

print()

# Another example usage
def make_power(n):
    def g(x):
        return x**n
    return g

square = make_power(2)
cube = make_power(3)
print(square(5)) # Output: 25
print(cube(5)) # Output: 125

val = make_prod(2)(3)
print(val) # Output: 6