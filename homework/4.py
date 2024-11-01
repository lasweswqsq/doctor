a=float(input())
n=int(input())
k=int(input())

x=1

for i in range(0,k):
    x= (a+(n-1)*(x**n))/(n*(x**(n-1)))
r=(abs(x-a**(1/n)))/a**(1/n)
print(f'{x:.10f}, {r:.10f}')