computer=['screen','mouse','cpu','gpu','keyboard']
print(computer[-1])
for i in range(5):
    print(computer[i])
    print('i need to use a',computer[i].title(),'to build a computer')

computer.append('website')
print(computer)

computer.insert(2,'internet')
print(computer)

del computer[1]
print(computer)
computer.sort()
print(computer)

#pop is outstanding
lollipop=computer.pop(3)
print(lollipop,computer)

computer.remove('screen')
print(computer)
























