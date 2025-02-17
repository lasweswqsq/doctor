class bakery(object):
    def __init__(self, name,tel):
        self.name = name
        self.tel = tel
        self.dict = {}
    def __str__(self):
        return self.name+" Tel "+self.tel
    def add_item(self, add_list):
        ans = []
        for i in add_list:
            if i in self.dict.keys():
                self.dict[i] += 1
            else:
                self.dict[i] = 1
            ans.append(self.dict[i])
        return ans
    
