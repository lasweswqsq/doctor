def summin(aa):
    ans = []
    for keys in aa.keys():
        ans.append(keys)
    def qiantao(aa):
        for i in aa:
            if isinstance(i, dict):
                qiantao(i.values())
                for j in i.keys():
                    ans.append(j)
            else:
                ans.append(i)
    qiantao(aa.values())
    return ans



aa = {'a': 1, 'b': 2, 'c': {'d': 3, 'e': 4, 'f': {'g': 5, 'h': 6}}}
print(summin(aa))