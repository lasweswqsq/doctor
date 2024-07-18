from math import *


class user:
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
            print('liitel ant look what you have done')


s=user(250,27)
user.sqrt(s)
user.average(s)
user.variance(s)
