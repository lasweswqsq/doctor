def fun(x,y):
    if x == y:
        return x
    else:
        return x+fun(x+1,y)

print(fun(1,23))