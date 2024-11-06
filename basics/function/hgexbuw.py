def calc(op, x, y): 
    return op(x,y)
def add(a,b):
    return a+b
def div(a,b):
    if b != 0:
        return a/b 
print("Denom was 0.")
res = calc(add, 2, 3)
print(res)


def do_twice(n,t, fn):
    return fn(fn(n,t),fn(n,t))
print(do_twice(3,6, lambda x,y : x**2 + y**2))
