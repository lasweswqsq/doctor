def check_index_exists(array, row, col):
    if row == -1 or col == -1:
        return 0
    try:
        array[row][col]
        return 1
    except IndexError:
        return 0
    except TypeError:
        return 0

x , y = map(int, input().split())
last = []
middle = []
for i in range(x):
    message = input()
    for j in range(y):
        middle.append(message[j*2])
    last.append(middle)
    middle = []
#print(last)
#print(is_valid_index(last, -1, 0))

for i in range(x):
    for j in range(y):
        if last[i][j] == 'I' or last[i][j] == 'E':
            pass
        else:
            hu = 0
            situation = [check_index_exists(last, i, j-1),check_index_exists(last, i, j+1),check_index_exists(last, i-1, j),check_index_exists(last, i+1, j)]
            if situation[0]== 1:
                if last[i][j-1] == 'I' or last[i][j-1] == 'i':
                    hu += 1
            if situation[1]== 1:
                if last[i][j+1] == 'I' or last[i][j+1] == 'i':
                    hu += 1
            if situation[2]== 1:
                if last[i-1][j] == 'I' or last[i-1][j] == 'i':
                    hu += 1
            if situation[3]== 1:
                if last[i+1][j] == 'I' or last[i+1][j] == 'i':
                    hu += 1
            
            if hu == sum(situation):
                last[i][j] = 'e'

for i in range(x):
    print(last[i])

                    
            



'''
3 4 
E I i I
i I i i
i I I i

5 5
E I i I E
i I i I I
I i I i E
I I i i I
i I I I i
'''