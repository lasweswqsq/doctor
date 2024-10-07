x= str(input())
p=int(x,16)
while (p>15):
    p='{:X}'.format(p)
    s=p
    p=0
    for i in range(len(s)):
        p=p+int(s[i],16)

first = int(x[0],16)


for i in range(1,len(x)):
    
    first = first ^ int(x[i],16)

print(hex(p)[2:].upper())
print(hex(first)[2:].upper())