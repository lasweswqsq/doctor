from die import Die



# create a D6
die = Die()

# roll the die 10 times and store the results in a list
results = []
for roll_num in range(1000):
    result = die.roll_num()
    results.append(result)


# print the results
#print("Results of rolling a D6 10 times:")
#for roll in results:
#    print(roll) 
frequencies=[]
poss_results = range(1,die.sides+1)
for i in poss_results:
    frequency = results.count(i)
    frequencies.append(frequency)
print("Frequency of each result:", frequencies)

#print(results)
# print the total of the results
#print("Total of the results:", sum(results))

import plotly.express as px
fig = px.bar(x=poss_results, y=frequencies, labels={"x": "Result", "y": "Frequency"})
fig.show()