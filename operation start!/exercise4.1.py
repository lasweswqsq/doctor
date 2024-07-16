game=['lightening aeroplanes','zombies vs plants','warm miracles','ginshin impact','arknights','stars and sky railway','sound waves','blue archive']
#for i in game:
#    print('i like',i.title())
#    print('i really like games.\n')
#print('these games can all be played on mobile phones\n')
print(len(game))
print(game[-3:])

rubbish=game[:]
rubbish.insert(6,'agency in a different world')
rubbish.append('strange things of a godess')

#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\operation start!\exercise4.1.py", line 10, in <module>
 #   rubbish.insert('qd')
#TypeError: insert expected 2 arguments, got 1

#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\operation start!\exercise4.1.py", line 11, in <module>
 #   rubbish.append['strange things of a godess']
 #   ~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#TypeError: 'builtin_function_or_method' object is not subscriptable


print(rubbish,game)

for i in rubbish[:3]:
    print ('the first is:',i,'.\n')
for i in rubbish[-3:]:
    print ('the last is:',i,'.\n')
for i in rubbish[2:6]:
    print ('the middle is:',i,'.\n')

for i in range(len(rubbish)):
    print (rubbish[i])














