import pprint

# print simple data type
number = 123456789
string = "Hello, world!"


# pprint simple data type
pprint.pprint(number)
pprint.pprint(string)
#123456789
#'Hello, world!'




# print list
a = [1, 2, 3, 4, 5435555555555555555555555555555344444444444444444444444444444444444444444444444444444444444444444444444, 6, 7, 8, 9, 10]

# pprint list
pprint.pprint(a)
#[1,
# 2,
# 3,
# 4,
# 5435555555555555555555555555555344444444444444444444444444444444444444444444444444444444444444444444444,
# 6,
# 7,
# 8,
# 9,
# 10]

# print dictionary
d = {"apple": 1, "banana": 2, "orange": 3, "pe5555555555555555ar": 4, "watermelon": 5}
print("Dictionary:", d)

# pprint dictionary
pprint.pprint(d)

#{'apple': 1,
# 'banana': 2,
# 'orange': 3,
# 'pe5555555555555555ar': 4,
# 'watermelon': 5}

# set the indent parameter
data = {"list": [1, 2, {"apple": 3, "banana": 4}], "dict": {"orange": [5, 6], "pear": 7}}
#pprint.pprint("Default Indent:")
pprint.pprint(data)

#pprint.pprint("Custom Indent:")
pprint.pprint(data, indent=10)

#{'dict': {'orange': [5, 6], 'pear': 7},
# 'list': [1, 2, {'apple': 3, 'banana': 4}]}
#{         'dict': {'orange': [5, 6], 'pear': 7},
#          'list': [1, 2, {'apple': 3, 'banana': 4}]}




























