l: list[float] = [float(j) for j in input().split()]
count: int = int(input())


def parse(lst: list[float], query: str, operation: str, index: list[int]) -> list[float]:
    target = (lst if len(index) == 0 else lst[index[0]:min(index[1], len(lst)):index[2]])
    if len(target) == 0:
        print('Querying on empty list! ')
        return lst
    if query == 'find':
        print(min(target) if operation == 'min' else max(target))
    elif query == 'index':
        print(target[int(operation)] if len(index) == 0 else target)
    elif query == 'compute':
        print((sum(target) / len(target)) if operation == 'avg' else sum(target))
    elif query == 'reorder':
        if operation == 'rev':
            target.reverse()
        else:
            target.sort(reverse=(operation == 'desc'))
        if len(index) != 0:
            lst = [(target[(i - index[0]) // index[2]] if (i in range(index[0], index[1], index[2])) else lst[i]) for i in range(len(lst))]
        print(lst)
    return lst


for k in range(count):
    op: list[str] = input().split(', ')
    q: str = op[0]
    o: str = op[1]
    f: list[int] = ([] if len(op) < 3 else [int(e) for e in op[2:]])
    l = parse(l, q, o, f)

