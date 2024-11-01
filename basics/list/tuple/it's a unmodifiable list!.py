deep=(293,3984,23794,23847823,23483)
print(deep[0])
print(deep)


#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\tuple\it's a unmodifiable list!.py", line 4, in <module>
#    deep[1]=34
 #   ~~~~^^^
#TypeError: 'tuple' object does not support item assignment

for i in deep:
    print (i)


#TypeError: 'tuple' object does not support item assignment
#PS C:\Users\Sunny\doctor> & C:/Users/Sunny/AppData/Local/Programs/Python/Python312/python.exe "c:/Users/Sunny/doctor/tuple/it's a unmodifiable list!.py"
#  File "c:\Users\Sunny\doctor\tuple\it's a unmodifiable list!.py", line 13
#    print i
#    ^^^^^^^
#SyntaxError: Missing parentheses in call to 'print'. Did you mean print(...)?

deep=(34,23)
print(deep)






















