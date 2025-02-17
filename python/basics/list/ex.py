def square_list(L):
    for i in range(len(L)): 
        L[i] = L[i]**2
Lin = [2,3,4]
print("before fcn call:",Lin) # prints [2,3,4]
square_list(Lin) 
print("after fcn call:",Lin) # prints [4,9,16]