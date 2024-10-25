origin = str(input())
stock = []
t=''
for i in origin:
    if i != " ":
        t+=i
    else:
        t=float(t)      
        stock.append(t)
        t=''
stock.append(float(t))
#print(stock)

i=0
query_number = int(input())
for er in range(query_number):
    current_list = []
    query = str(input())
    if query[6:9] == "min" and len(query) < 10:
        print(float(min(stock)))
    elif query[6:9] == "min":
        l=[]
        t=''
        for j in query[11:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")

        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            print(float(min(current_list)))

    elif query[6:9] == "max" and len(query) < 10:
        print(float(max(stock)))
    elif query[6:9] == "max":
        l=[]
        t=''
        for j in query[11:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            print(float(max(current_list)))

    elif query[0:5] == "index" and len(query) < 10:
        s = float(query[6:])
        if abs(s) > len(stock):
            print("Querying on empty list!")
        else:
            print(float(stock[int(s)]))
    elif query[0:5] == "index":  
        l=[]
        t=''
        for j in query[14:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            print(current_list)
    if query[9:12] == "avg" and len(query) < 13:
        print(float(sum(stock)/len(stock)))
    elif query[9:12] == "avg":
        l=[]
        t=''
        for j in query[14:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            print(float(sum(current_list)/len(current_list)))
    elif query[9:12] == "all" and len(query) < 13:
        print(float(sum(stock)))
    elif query[9:12] == "all":
        l=[]
        t=''
        for j in query[14:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            print(float(sum(current_list)))
    elif query[9:12] == "asc" and len(query) < 13:
        print(sorted(stock))
    elif query[9:12] == "asc":
        l=[]
        t=''
        for j in query[14:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        elif max(l) > len(stock):
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            cuurent_list = sorted(current_list)
            if l[2]>0:
                dig=0
            else:
                dig=len(current_list)-1
            pass_list = stock
            for x in range(l[0],l[1],l[2]):
                if l[2]>0:
                    pass_list[x] = current_list[dig]
                    dig += 1
                if l[2]<0:
                    pass_list[x] = current_list[dig]
                    dig -= 1
            print(pass_list)
            
    elif query[9:13] == "desc" and len(query) < 14:
        print(sorted(stock,reverse=True))
        
    elif query[9:13] == "desc":
        l=[]
        t=''
        for j in query[15:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            current_list = sorted(current_list,reverse=True)
            if l[2]>0:
                dig=0
            else:
                dig=len(current_list)-1
            pass_list = stock
            for x in range(l[0],l[1],l[2]):
                if l[2]>0:
                    pass_list[x] = current_list[dig]
                    dig += 1
                if l[2]<0:
                    pass_list[x] = current_list[dig]
                    dig -= 1
            print(pass_list)
    elif query[9:12] == "rev" and len(query) < 13:
        print(stock[::-1])
    elif query[9:12] == "rev":
        l=[]
        t=''
        for j in query[14:]:
            if j != "," and j != " ":
                t+=j
            elif j == ",":
                i=i+1
            else:
                t=int(t)
                l.append(t)
                t=''      
        l.append(int(t))
        if (l[1]-l[0])*l[2] < 0:
            print("Querying on empty list!")
        else:
            for x in range(l[0],l[1],l[2]):
                if x >= len(stock):
                    i=i+1
                else:
                    current_list.append(stock[x])
            current_list = current_list[::-1]
            if l[2]>0:
                dig=0
            else:
                dig=len(current_list)-1
            pass_list = stock
            for x in range(l[0],l[1],l[2]):
                if l[2]>0:
                    pass_list[x] = current_list[dig]
                    dig += 1
                if l[2]<0:
                    pass_list[x] = current_list[dig]
                    dig -= 1
            print(pass_list)
'''
1 4 5 3 4 2 5 -2 -3 0 2
5
find, min
find, max, 0, 3, 1
compute, avg, 2, 12, 1
reorder, rev
reorder, asc, 1, 6, 1
'''
