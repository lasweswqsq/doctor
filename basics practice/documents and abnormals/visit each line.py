from pathlib import Path
import pprint

path=Path("blog.txt")
c=path.read_text()
l=c.splitlines()
'''
pprint.pprint(l)
for i in l:
    print(i)
'''

d=''
for i in l:
    d += i

print(d,'\n',len(d))





