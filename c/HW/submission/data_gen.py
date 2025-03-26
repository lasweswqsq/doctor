import random
import string
import sys
print(int(sys.argv[1]))
for i in range(int(sys.argv[1]) - 1):
    length = random.randint(1, int(sys.argv[2]))
    password = ''.join(random.choices(string.ascii_letters + string.digits + string.punctuation, k=length))
    print(length)
    print(password)
print(1)
print('a')
