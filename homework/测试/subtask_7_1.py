def check(piz):

    sq11 = [5, 5]
    sq12 = [6, 6, 6, 6]

    res = piz(sequence_1=sq11)
    res = piz(sequence_1=sq12)

    ans = [(6, 0), (6, 1), (6, 2), (6, 3)]

    if res == ans:
        print("Accepted.")
    else:
        print("Wrong Answer.")