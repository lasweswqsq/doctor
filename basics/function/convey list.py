jessica=['m','p','o','t']
def pc(x):
    print('the elements in the list are:' )
    for i in x:
        print(i)
def pr(x):
    tissue=[]
    t=x[:]
    while t:
        dk=t.pop()
        tissue.append(dk)
    print(tissue)

#PS C:\Users\Sunny\doctor> & C:/Users/Sunny/AppData/Local/Programs/Python/Python312/python.exe "c:/Users/Sunny/doctor/function/convey list.py"
#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\function\convey list.py", line 15, in <module>
#    pr(jessica)
#  File "c:\Users\Sunny\doctor\function\convey list.py", line 10, in pr
 #   dk=t.pop()
 #      ^^^^^^^
#IndexError: pop from empty list

pr(jessica)
print(jessica)
