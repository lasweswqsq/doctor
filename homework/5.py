mes=str(input())
answer=0
for i in range(1,len(mes)+1):
    for j in range(0,len(mes)-i+1):
        c = mes[j:j+i]
        if c in mes[j+i:]:
            answer = c
            break
if answer == 0:
    print("No repeated pattern found")
else:
    print(answer)
        