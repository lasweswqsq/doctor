def piz(sequence_1=[], sequence_2=[]):
    try:
        a = list(sequence_1)
        b = list(sequence_2)
    except TypeError:
        print(f"Find a non-list but iterable object {object_type}. Bad ++C Committee!")