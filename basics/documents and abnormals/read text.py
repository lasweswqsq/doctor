from pathlib import Path
path=Path('666.txt')

contents=path.read_text()


print(contents)


peas=Path('blog.txt')
contents=peas.read_text()


print(contents)
contents=contents.rstrip()
print(contents)
