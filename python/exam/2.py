a = map(int, input().split())
a = list(a)
a.sort()
if len(a) %2 == 0:
    print((a[int(len(a)/2)]+a[int(len(a)/2)-1])/2)
else:
    print(a[int(len(a)/2)])
    