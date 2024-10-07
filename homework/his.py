if False:
    a,n,k=[float(input()),int(input()),int(input())]

    x=1
    for i in range(0, k):
        x=(a+(n-1)*(x**n))/(n*(x**(n-1)))
    r=abs(x/a**(1/n))-1
    print(f'{x:.10f}, {r:.10f}')


s = input()

r = ['']
index = 0
while index < len(s):
    i = s[index]
    flag = False;
    if s.count(i+'A') > 1:
        r.append(i+'A')
        flag = True
    if s.count(i+'C') > 1:
        r.append(i+'C')
        flag = True
    if s.count(i+'G') > 1:
        r.append(i+'G')
        flag = True
    if s.count(i+'T') > 1:
        r.append(i+'T')
        flag = True
    if flag:
        r.remove(i)
    else:
        break
print(r[0])