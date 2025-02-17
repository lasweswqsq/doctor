my_d ={'Ana':{'mq':[10], 'ps':[10,10]},
'Bob':{'ps':[7,8], 'mq':[8]},
'Eric':{'mq':[3], 'ps':[0]} }
def get_average(data, what):
    all_data = []
    for stud in data.keys():
        all_data = all_data + data[stud][what]
#INSERT LINE HERE
    return sum(all_data)/len(all_data)
print(get_average(my_d, 'ps')) # should print 6.5
print(get_average(my_d,'mq')) # should print 7.25
'''
Given the dict my_d, and the outline of a function to compute an average, which line should
be inserted where indicated so that get_average(my_d, 'mq') computes average
for all 'mq' entries? i.e. find average of all mq scores for all students.
A) all_data = all_data + data[stud][what]
B) all_data.append(data[stud][what])
C) all_data = all_data + data[stud[what]]
D) all_data.append(data[stud[what]])
'''