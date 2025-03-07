word_dict = {'rah':2,
'ah':3,
'rom':1,
'mah':3,
'ro':1}
def pig(word_dict):
    x = max(word_dict.values())
    list = []
    lower_list = []
    while len(word_dict) != 0 :
        x = max(word_dict.values())
        for k in word_dict:
            if word_dict[k] == x:
                lower_list.append(k)
        for i in lower_list:
            del word_dict[i]
        list.append({x:lower_list})
        lower_list = []
    return list
print(pig(word_dict))


            
