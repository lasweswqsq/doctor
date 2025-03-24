import random
import string

num = int(input())
max_len = int(input())
print(num)
for i in range(num):
    length = random.randint(1, max_len)
    password = ''.join(random.choices(string.ascii_letters + string.digits + string.punctuation, k=length))
    print(length)
    print(password)
