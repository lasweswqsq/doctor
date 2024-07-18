import random
a = random.random()
b = random.random()
print(a,b)  
#0.14950126763787908 0.18635283756700527

a = random.uniform(5,10)
b = random.uniform(10,5)
print(a,b)


a = random.randint(2,4)
b = random.randint(1,5)
print(a,b)

a = random.randrange(1,10,2)
b = random.randrange(1,10,2)
c = random.randrange(50)
print(a,'\n',b)
# 2 3
print(c)
# 48

list_1 = ['python','java','c']
str_1 = "i love python"
tuple_1 = (1,2,'kai')
print(random.choice(list_1))  #java
print(random.choice(str_1))   #v
print(random.choice(tuple_1)) #2


list_1 = ['python','java','c','c++']
random.shuffle(list_1)
print(list_1)
# ['c', 'python', 'java', 'c++']

list_1 = ['one','two','three','four']
slice = random.sample(list_1,2)
print(list_1)  # ['one', 'two', 'three', 'four']
print(slice)   # ['two', 'three']