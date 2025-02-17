times= int(input())
distance = [[0,0,0]]
for i in range(times):
    x,y,time = map(int,input().split())
    se = input().split()
    print(se)
    distance.append([x,y,time])
#print(distance)

s = 0
for i in range(1,times):
    s += ((distance[i][1]-distance[i+1][1])**2 + (distance[i][0]-distance[i+1][0])**2)**0.5
print(f"{s / (distance[times][2]-distance[1][2]):.3f}")

w = int(input())
s=0
for i in range(w):
    x,y = map(int,input().split())
    for j in range(x+1,y+1):
        s += ((distance[j][1]-distance[j+1][1])**2 + (distance[j][0]-distance[j+1][0])**2)**0.5
    print(f"{s / (distance[y+1][2]-distance[x+1][2]):.3f}")
    s=0


'''
4
1 2 1
7 3 5
4 8 12
2 1 18
1
1 3

5
48 8 2
-83 -85 4
60 14 11
-37 -37 19
-15 -31 20
2
3 4
0 2

'''