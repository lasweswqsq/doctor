def bisection_root(x):
    epsilon = 0.01
    low = 0
    high = x  # 使用小写的 x
    guess = (high + low) / 2.0
    
    while abs(guess**2 - x) >= epsilon:
        if guess**2 < x:
            low = guess
        else:
            high = guess
        
        guess = (high + low) / 2.0  # 更新 guess 值

    return guess  # 返回结果

def bisection_root_new(x, epsilon=0.01):

    low = 0
    high = x  # 使用小写的 x
    guess = (high + low) / 2.0
    
    while abs(guess**2 - x) >= epsilon:
        if guess**2 < x:
            low = guess
        else:
            high = guess
        
        guess = (high + low) / 2.0  # 更新 guess 值

    return guess  # 返回结果
print(bisection_root_new(epsilon=0.001, x=123))