a = 3
cnt = 0
while(a%107!=90):
    a = a*a
    a = a%107
    cnt += 1
    print(a,cnt)
print(cnt)
print((3^(36*37))%107)