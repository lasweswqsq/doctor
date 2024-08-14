#print(5/0)

#ZeroDivisionError: division by zero

try:
    print(5/0)
except ZeroDivisionError:
    print('youn auhunwe ewir!')


from pathlib import Path
path = Path('eiug.txt')
try:
    portu=path.read_text(encoding='utf-8')
except FileNotFoundError:
    print('sorry, i will shoot some sperms on myself')




