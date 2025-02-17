def piz(sequence_1=None, sequence_2=None):
    import random
#    list_1 = ["Find a non-iterable object <class 'int'>. Bad ++C Committee!","Find a non-iterable object <class 'bool'>. Bad ++C Committee!"]
    flag_1 = False
    flag_2 = False
    if sequence_2 is None:
        sequence_2 = []
        flag_2 = True
    if sequence_1 is None:
        sequence_1 = []
        flag_1 = True
    ans = []
    try:
        for i in sequence_1:
            pass
        try:
            for j in sequence_2:
                pass
            a = list(sequence_1)
            b = list(sequence_2)
            if len(a)== len(b):
                for i,j in zip(a,b):
                    ans.append((i,j))
                if type(sequence_1) == list:
                    if type(sequence_2) != list:
                        ans.append(f"Find a non-list but iterable object {type(sequence_2)}. Bad ++C Committee!")
                else:
                    ans.append(f"Find a non-list but iterable object {type(sequence_1)}. Bad ++C Committee!")
            elif len(a)<len(b):
                for i,j in zip(a,b):
                    ans.append((i,j))
                for i in range(len(b)-len(a)):
                    ans.append((i,b[i+len(a)]))
                    if type(sequence_1) == list:
                        sequence_1.append(i)
                if type(sequence_1) == list:
                    if type(sequence_2) != list:
                        ans.append(f"Find a non-list but iterable object {type(sequence_2)}. Bad ++C Committee!")
                else:
                    ans.append(f"Find a non-list but iterable object {type(sequence_1)}. Bad ++C Committee!")
            else:
                for i,j in zip(a,b):
                    ans.append((i,j))
                for i in range(len(a)-len(b)):
                    ans.append((a[i+len(b)],i))
                    if type(sequence_2) == list:
                        sequence_2.append(i)
                if type(sequence_1) == list:
                    if type(sequence_2) != list:
                        ans.append(f"Find a non-list but iterable object {type(sequence_2)}. Bad ++C Committee!")
                else:
                    ans.append(f"Find a non-list but iterable object {type(sequence_1)}. Bad ++C Committee!")
            if flag_1:
                sequence_1 = None
            if flag_2:
                sequence_2 = None
            return ans
        except Exception:
            raise TypeError(f"Find a non-iterable object {type(sequence_2)}. Bad ++C Committee!")
    except Exception as e:
        if e.args[0] == f"Find a non-iterable object {type(sequence_2)}. Bad ++C Committee!":
            raise e
        else:
            raise TypeError(f"Find a non-iterable object {type(sequence_1)}. Bad ++C Committee!")



    

def check(piz):
    sq1 = 'grvytv'
    sq2 = 0

    try:
        res = piz(sequence_1=sq1, sequence_2=sq2)
        print(e.args[0])
    except TypeError as e:
        if e.args[0] == "Find a non-iterable object <class 'int'>. Bad ++C Committee!":
            print("Accepted.")
        else:
            print("Message is wrong, your message is %s" % e.args[0])
    else:
        print("Wrong Answer.")


check(piz)