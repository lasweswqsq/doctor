heng=[]
shu=[]
number=int(input())
for i in range(number):
    acc=str(input())
    c=0
    while (acc[c]!=' '):
        c=c+1
    heng.append(float(acc[:c]))
    shu.append(float(acc[c+1:]))
x=0
xx=0
y=0
xy=0
for i in range (number):
    xy=xy + heng[i]*shu[i]
    xx = xx + heng[i]**2
    x = x + heng[i]
    y = y + shu[i]
m = (number*xy - x*y)/(number*xx - x*x)
b = (y - m*x)/number

print(f"y = {m:.2f}x + {b:.2f}")
