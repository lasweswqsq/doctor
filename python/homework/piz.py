def nonIterable(obj) -> bool:
    try:
        obj.__iter__()
    except:
        return True
    return False


def isList(obj) -> bool:
    return type([]) == type(obj)


def piz(sequence_1=None, sequence_2=None) -> list[tuple[int, int]]:
    flag_1 = False
    flag_2 = False
    if sequence_2 is None:
        sequence_2 = []
        flag_2 = True
    if sequence_1 is None:
        sequence_1 = []
        flag_1 = True
    if nonIterable(sequence_1):
        raise TypeError(f"Find a non-iterable object {type(sequence_1)}. Bad ++C Committee!")
    if nonIterable(sequence_2):
        raise TypeError(f"Find a non-iterable object {type(sequence_2)}. Bad ++C Committee!")
    nonList = None
    (l1, nonList) = (sequence_1, None) if isList(sequence_1) else (list(sequence_1), sequence_1)
    (l2, nonList) = (sequence_2, nonList) if isList(sequence_2) else (list(sequence_2), (nonList if nonList is not None else sequence_2))
    if len(l1) != len(l2):
        shorter = l1 if len(l1) < len(l2) else l2
        j = 0
        for i in range(min(len(l1), len(l2)), max(len(l1), len(l2))):
            shorter.append(j)
            j += 1
    result: list[any] = [(l1[i], l2[i]) for i in range(len(l1))]
    if nonList is not None:
        result.append(f"Find a non-list but iterable object {type(nonList)}. Bad ++C Committee!")
    if flag_1:
        sequence_1 = None
    if flag_2:
        sequence_2 = None
    return result

# judge if sequence_1 and sequence_2 are iterable
# judge if sequence_1 and sequence_2 are lists
# if not, use list(object) to change
# otherwise do nothing
# do the extension
# if the shorter one is a list, the extension should be done on the original list
# zip the two lists and return


while True:
    exec(input())
