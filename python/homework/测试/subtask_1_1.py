def check(piz):
    sq1 = [1, 2, 3]
    sq2 = [4, 5, 6]
    ans = [(1, 4), (2, 5), (3, 6)]
    res = piz(sequence_1=sq1, sequence_2=sq2)
    if res == ans:
        print("Accepted.")
    else:
        print("Wrong Answer.")