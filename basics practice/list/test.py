#TypeError: '<' not supported between instances of 'str' and 'int'
#what?!
cret=[24354,3465,2123,490,888,43]
cret.sort(reverse=True)
print(cret)

#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\list\ test.py", line 6, in <module>
#   print(cret.sorted())
#        ^^^^^^^^^^^
#AttributeError: 'list' object has no attribute 'sorted'. Did you mean: 'sort'?

print(sorted(cret))
print(cret)

cret=['2','shgaf','3.455','GFYDFT','"']
cret.sort()
print(cret)