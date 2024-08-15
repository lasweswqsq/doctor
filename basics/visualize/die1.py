from die import Die



# create a D6
die = Die()

# roll the die 10 times and store the results in a list
results = []
for roll_num in range(10):
    result = die.roll_num()
    results.append(result)


# print the results
print("Results of rolling a D6 10 times:")
for roll in results:
    print(roll) 

# print the total of the results
#print("Total of the results:", sum(results))