fragments = ['water', 'oxygen', 'blood', 'lungs', 'heart']
print(id(fragments))
fragments.append('kidneys')
print(id(fragments))

fragments = []
print(id(fragments))
fragments.clear()
print(id(fragments))

dr = ('John', 'Doe', 25)
print(id(dr))
dr = ('Jane', 'Smith', 30)
print(id(dr))

#That's it! We have learned how to get the memory address of an object in Python.
#How to check that it’s the same object in memory?
L = [1, 2, 3, 4, 5]
Lcopy = L[:]
print(id(L))
print(Lcopy)

#The id() function returns the memory address of an object in Python. If two objects have the same memory address, they are the same object in memory.

