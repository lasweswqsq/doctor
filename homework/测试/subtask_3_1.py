def check(piz):
    sq2 = [114, 514]
    ans = [(0, 114), (1, 514)]
    res = piz(sequence_2=sq2)
    if res == ans:
        print("Accepted.")
    else:
        print("Wrong Answer.")