from pathlib import Path
path=Path('blog.txt')
c=path.read_text()
print(c.lower().count('a'))