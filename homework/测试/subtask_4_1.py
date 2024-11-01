def check(piz):
    sq1 = (1, 9, 1, 9, 8, 1, 0)
    sq2 = (114, 514)
    ans = [(1, 114), (9, 514), (1, 0), (9, 1), (8, 2), (1, 3), (0, 4), "Find a non-list but iterable object <class 'tuple'>. Bad ++C Committee!"]

    res = piz(sequence_1=sq1, sequence_2=sq2)

    if res == ans:
        print("Accepted.")
    else:
        print("Wrong Answer.")
