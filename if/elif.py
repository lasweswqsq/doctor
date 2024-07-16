import random


something=random.randint(1,246)
print(something)
if (something>=123):
    print("that's good (glasses)")
elif(something<123 )and (something>=100):
    print("that's awful (grievance)")
else:
    print("you win the lottery!!!!!!!")
    #we can use elif in replacement of else in order to secure that there aren't bad data in our program.
#if we want to operate only one mode, use if-elif-else
#if we want to operate a plenty of individual modes, use multiple "else" instead