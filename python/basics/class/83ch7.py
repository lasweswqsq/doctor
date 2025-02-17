class SimpleFraction(object): 
    def init (self, n, d):
        self.num = n
        self.denom = d
    def times(self, oth):
        top = self.num*oth.num
        bottom = self.denom*oth.denom
        return top/bottom