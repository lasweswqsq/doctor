'''
import copy
a = [1, 2, 3, 4, 5,[6,7,8]]
b = a.copy()
b = a
b[0] = 12
b[5][2] = 2332
print(a,id(a))
print(b,id(b))
'''
a = [1, 2, 3, 4, 5,[6,7,8]]
b = []
for i in a:
    iuy = i
    b.append(iuy)
b[0] = 12
b[5][2] = 2332
print(a,id(a))
print(b,id(b))

asw = "ewydu"
jshd = asw
jshd = "jshd"
print(asw,id(asw))
print(jshd,id(jshd))

a = [len(x) for x in ['xy'
,
'abcd'
, 7,
'4.0'] if type(x) ==
str]
print(a)