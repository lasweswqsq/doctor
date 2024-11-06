s = "I<3 cs &u?" #→ s is a string
L = list(s)  
L1 = s.split(' ') 
L2 = s.split('<') 

print(L) 
print(L1) 
print(L2) 

# Output:
# ['I', '<', '3', 'c', 's', '&', 'u', '?']
# ['I<3', 'cs', '&u?']
# ['I', '3 cs &u?']