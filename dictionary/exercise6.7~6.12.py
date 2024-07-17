font={'s': 'special week', 'p': 239, 'profile': 666, 'lancer': 'hinata'}
induce={'s': 'special week', 'p': 239, 'profile': 666, 'lancer': 'hinata'}
ine={'s': 'special week', 'p': 239, 'profile': 666, 'lancer': 'hinata'}

foriegn=[font,induce,ine]
print(foriegn)

for i in foriegn:
    print(i,'\n')

food={'baren':['fried chichen wings','potato chips','tomato with eggs'],'gen':['little fish','roasted duck','buns'],'e3e':['wuloong tea','bacon with cream']}
for i in food.keys():
    print(i,'like to eat')
    for j in food.get(i):
        print(j)
    print('\n')

food={'baren':{'fried chichen wings':1,'potato chips':2,'tomato with eggs':3},'gen':{'little fish':4,'roasted duck':5,'buns':5},'e3e':{'wuloong tea':6,'bacon with cream':7}}
for i in food.keys():
    print(i,'like to eat')
    for p,j in food.get(i).items():
        print(i,'likes to eat',j,p)
    print('\n')















