def iu(n:int, p:float) -> float:
    if n==1:
        return p
    elif n>=1:
        return p*iu(n-1,p)
    else:
        return "Value of n should be greater than or equal to 1"
    
print(iu(5,0.5))
print(iu(1,0.5))
print(iu(0,0.5))