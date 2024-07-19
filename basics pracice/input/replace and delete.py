u=['adapt to','adapt for','induce','recognize']
c=[]
while u:
    u.reverse()
    print(u)
    #u.pop()
    pp=u.pop()
    print('clearing',pp)
    c.append(pp)
print('good, lucky^-^')
for i in c:
    print(i)


classics=[1,1,1,1,'halmet','Mike White','oselo','liear king',1,1,1,1]
while 1 in classics:
    classics.remove(1)
    print(classics)