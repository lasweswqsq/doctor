def check(piz):

    sq1 = (1, 2, 3, 4, 5)
    sq2 = [6, 7]

    res = piz(sq1, sq2)

    ans = [(1, 6), (2, 7), (3, 0), (4, 1), (5, 2), "Find a non-list but iterable object <class 'tuple'>. Bad ++C Committee!"]
    ans_sq2 = [6, 7, 0, 1, 2]

    if res == ans:
        if sq2 == ans_sq2:
            print("Accepted.")
        else:
            print("The origin list wasn't completed correctly.")
    else:
        print("Wrong Answer.")