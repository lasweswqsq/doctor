import pprint
import random
t = ('yellow','green','red')
p=(12,18,24,36,48,96)
sp=('slow','medium','fast')
cd=[]
for i in range(30):
    col={'color':random.choice(t),'points':random.choice(p),'speed':random.choice(sp)}
    cd.append(col)
print(i,'\n',cd)
print(cd[1].get('color'))

ese=0
for i in range(30):
    if cd[i].get('color')=='yellow':
        ese += 1
        cd[i]['color']='ahhhhhhhhhhhhhhhhhhhhhh'
print(ese,'\n',cd)
