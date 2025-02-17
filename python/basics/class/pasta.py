from math import *


class user: #capitalize the first letter
    def __init__(self,y,z):
        self.y=y
        self.z=z
    def average(self):
        out=(self.y+self.z)/2
        print(out)
    def variance(self):
        out=(self.y**2+self.z**2)/2-((self.y+self.z)/2)**2
        print(out)
    def sqrt(self):
        if (sqrt(self.y)%1==0):
            print('you are a genius')
        else:
            print('little ant look what you have done')

'''
s=user(250,27)
user.sqrt(s)
user.average(s)
user.variance(s)
'''

class upper(user):
    def __init__(self, y, z):
        self.y=y
        self.z=z
        #initialize father category
        super().__init__(y, z)
    def average(self):
        out=sqrt((self.y**2+self.z**2)/2)
        print(out)
    def nmb(self):
        print(self.y)
        while(self.y<=2020):
            self.y=self.y+1
            q=1
            cnt=0
            while(q<self.y-1):
                q=q+1
                if (self.y%q==0):
                    cnt+=1
                
            if (cnt==0):
                print(self.y,'is a prime number')
            else:
                print(self.y,'is a composite number, it has',cnt+2,'prime factors.')
        
'''
p=upper(2,2132)
#upper.nmb(p)
upper.average(s)
#s could be inherited
'''

class beta(upper):
    def __init__(self, y, z):
        self.y=y
        self.z=z
        super().__init__(y, z)
    def compare(self):
        if (self.y>=self.z):
            print('a is bigger than b')
        else:
            print('shift!!')
    def show(self):
        print('you can go to devil')
    def upgrade(self):
        if self.y!=65:
            self.y=65
        print(6)




'''
s=beta(232,204)
beta.compare(s)
beta.show(s)
beta.upgrade(s)
beta.compare(s)
'''