import random


red=[]
blue=[]
win=[]
for i in range(1,10):
    red.append(i)
for i in range(1,5):
    blue.append(i)

red1=red[:]
for i in range(6):
    k=random.choice(red1)
#    print(k)
    red1.remove(k)
    win.append(('red',k))
k=random.choice(blue)
win.append(('blue',k))
win.sort()
print(win)

red1=red[:]
cnt=0
spare=[]
while spare!=win:
    spare=[]
    red1=red[:]
    cnt += 1
    for i in range(6):
        k=random.choice(red1)
#    print(k)
        red1.remove(k)
        spare.append(('red',k))
    k=random.choice(blue)
    spare.append(('blue',k))
    spare.sort()
    print(spare)
print(cnt,win)



