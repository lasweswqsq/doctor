def sum_digits(s):
#""" s is a non-empty string containing digits. 
#Returns sum of all chars that are digits """ 
    assert len(s) != 0, "s is empty"
#"s is empty"
    total = 0
    for char in s: 
        try:
            val = int(char) 
            total += val
            return total
        except:
            raise ValueError("string contained a character")
        
print(sum_digits("12345")) # returns 15
print(sum_digits("12345a")) # raises ValueError("string contained a character")
print(sum_digits("")) # raises ValueError("string contained a character")
#sum_digits("") # raises ValueError("string contained a character")
#sum_digits("12345a") # raises ValueError("string contained a character")