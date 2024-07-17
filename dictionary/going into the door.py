spe = {'s':'special week','p':234}
print(spe['s'])
print(spe['p'])

#PS C:\Users\Sunny\doctor> & C:/Users/Sunny/AppData/Local/Programs/Python/Python312/python.exe "c:/Users/Sunny/doctor/dictionary/going into the door.py"
#  File "c:\Users\Sunny\doctor\dictionary\going into the door.py", line 1
 #   spe = {'s':'special week','p'=234}
#                                ^
#SyntaxError: ':' expected after dictionary key

#print(spe[234])

#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\dictionary\going into the door.py", line 11, in <module>
#    print(spe[234])
#          ~~~^^^^^
#KeyError: 234

spe['profile']=666
spe['lancer']='hinata'
print(spe)

spe['p'] += 5
print(spe)

del spe['lancer']
print(spe)

#{'s': 'special week', 'p': 239, 'profile': 666, 'lancer': 'hinata'}
#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\dictionary\going into the door.py", line 26, in <module>
#    del spe['laner']
#        ~~~^^^^^^^^^
#KeyError: 'laner'

spe = {'s':'special week','p':234,'t':"#"}
print(spe.get(78,'yu'))

re={'a':'revenue','b':'indicate','c':'affordability'}
for i,j in re.items():
    print(i,'represents',j)

#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\dictionary\going into the door.py", line 40, in <module>
#    for i,j in re():
#               ^^^^
#TypeError: 'dict' object is not callable

























