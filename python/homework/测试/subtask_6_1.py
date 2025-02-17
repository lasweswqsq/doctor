def check(piz):
    sq1 = "abcdefg"
    sq2 = "hijkl"

    res = piz(sequence_1=sq1, sequence_2=sq2)
    ans = [('a', 'h'), ('b', 'i'), ('c', 'j'), ('d', 'k'), ('e', 'l'), ('f', 0), ('g', 1), "Find a non-list but iterable object <class 'str'>. Bad ++C Committee!"]

    if res == ans:
        print("Accepted.")
    else:
        print("Wrong Answer.")
