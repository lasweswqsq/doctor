person=['hg','brth','ercg','23','pasta','shortage','authority']
re={'hg':'revenue','brth':'indicate','ergc':'affordability','werfd':'airline','233e':'curious','fFW':'curiosity','dsf':'k',8:'k'}

for i,j in re.items():
    print(i,'represents',j)
for i in re.keys():
    print(i)
for i in re.values():
    print(i)

for i in sorted(re.values()):
    print(i)

print("\n")
for i in sorted(set(re.values())):
    print(i.title())

passenger={12,12,23,345,34532,23,34,5,43,45,3,23,23,45,34,5,345,3,45,34,5,3,453,4,53,45}
print(sorted(passenger))

for i in person:
    if i in re.keys():
        print('thank you for your cooperation, we hope to see you soon',i,'.\n',re[i].upper(),'\n')
    elif i not in re.keys():
        print('hurry up',i,'not for next time.\n')
















