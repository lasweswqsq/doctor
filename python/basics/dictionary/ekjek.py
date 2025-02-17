def count_matches(d):
    """ 
    d is a dict
    Returns how many entries in d have the key equal to its value 
    """
    cu = 0
    for k, v in d.items():
        if k == v:
            cu += 1
    return cu

# Testing the function
# for example
d = {1:2, 3:4, 5:6}
print(count_matches(d)) # prints 0
d = {1:2, 'a':'a', 5:5}
print(count_matches(d)) # prints 2