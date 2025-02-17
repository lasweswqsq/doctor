from difflib import restore
t1=''
t2=[]

def f(x,y='3'):
    s=f"{x} sings {y}\n"
    p={"singer":x,"album":y}
    t1 += s
#    t2 += p
    return t1

while True:
    x1=input("singer:")
    x2=input("album:")
    if x1=='no' or x2=="no":
        break
    else:
        f(x1,x2)

t1=''
t2=[]



l=f("miku",'travel to the future')
print(l)