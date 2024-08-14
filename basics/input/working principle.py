'''
#m=input('what do you want to shoot:')
#print('hey',m)

s=input('number: hurry up!')
s=int(s)
if (s%5==0):
    print('it can be modified by five')
else:
    print('it can not be modified by five')


typist='which city would you like to visit:\nif you want to quit, please input no'
while True:
    p=input(typist)
    if (p=='no'):
        break
    else:
        print('i had never been to',p,'before, may i join you?')


while True:
    print(21)
'''
#Traceback (most recent call last):
#  File "c:\Users\Sunny\doctor\input\working principle.py", line 23, in <module>
#    print(21)
#KeyboardInterrupt


t=1
while(t<=2020):
    t=t+1
    q=1
    cnt=0
    while(q<t-1):
        q=q+1
        if (t%q==0):
            cnt+=1
        else:
            continue
    if (cnt==0):
        print(t,'is a prime number')
    else:
        print(t,'is a composite number, it has',cnt+2,'prime factors.')





