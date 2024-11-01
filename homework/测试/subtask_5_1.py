def check(piz):
    sq1 = 0
    sq2 = 0

    try:
        res = piz(sequence_1=sq1, sequence_2=sq2)
    except TypeError as e:
        if e.args[0] == "Find a non-iterable object <class 'int'>. Bad ++C Committee!":
            print("Accepted.")
        else:
            print("Message is wrong, your message is %s" % e.args[0])
    else:
        print("Wrong Answer.")

