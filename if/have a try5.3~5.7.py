import random


op=random.randint(12,14)
if(op==13):
    print("you silly guy!")

cnt=0
if(op==13):
    cnt += 5
    print('you win',cnt,'points')
elif(op==12):
    cnt += 10
    print('you win',cnt,'points')
else:
    cnt += 20
    print('you win',cnt,'points')

ff=[2454,536,3345,234,2,41,14]
target=random.randint(2,3345)

gamber=0
cnt=0
while(gamber != 1): 
    target=random.randint(2,3345)
    if target in ff:
        gamber=1
        print('you won 5000 dollars minus 5 pounds!')
    if target not in ff:
        gamber=0
        cnt=cnt+1
        print('here is one cent of console')
print(cnt)

    #PS C:\Users\Sunny\doctor> & C:/Users/Sunny/AppData/Local/Programs/Python/Python312/python.exe "c:/Users/Sunny/doctor/if/have a try5.3~5.7.py"
  #File "c:\Users\Sunny\doctor\if\have a try5.3~5.7.py", line 26
    #print('you won 5000 dollars minus 5 pounds!')
#IndentationError: unexpected indent