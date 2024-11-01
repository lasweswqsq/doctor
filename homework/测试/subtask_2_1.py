def check(piz):

    sq1 = [1, 9, 1, 9, 8, 1, 0]
    sq2 = [114, 514]
    ans = [(1, 114), (9, 514), (1, 0), (9, 1), (8, 2), (1, 3), (0, 4)]
    ans_sq2 = [114, 514, 0, 1, 2, 3, 4]
    res = piz(sequence_1=sq1, sequence_2=sq2)

    if res == ans:
        if sq2 == ans_sq2:
            print("Accepted.")
        else:
            print("The origin list wasn't completed correctly.")
    else:
        print("Wrong Answer.")