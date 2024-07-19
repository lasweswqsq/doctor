k={}
while True:
    s=input('what would you like to eat')
    d=input('what would you like to drink')
    k[s]=d
    if (s=='no'):
        break
for i,j in k.items():
    print(i,'\t',j)

