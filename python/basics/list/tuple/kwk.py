def mean(tty,*args):
    tot = 0
    for a in args:
        tot += a
    return tot*tty / len(args)

print(mean(1, 2, 3, 4, 5)) # Output: 3.0
print(mean(1, 2, 3, 4, 5, 6)) # Output: 3.5