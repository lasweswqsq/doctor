def remove_elem(L, e): 
    return [x for x in L if x!= e] 


def remove_elem_2(L, e): 
    for i in range(len(L)-1,-1,-1):
        if L[i] == e:
            L.pop(i)
    return L 
L = [2,1,2,2,2]
print(remove_elem_2(L, 2)) # prints [1]