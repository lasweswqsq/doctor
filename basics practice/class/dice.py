import random as rd

class die:
    def __init__(self,times,number):
        self.y=times
        self.z=number
    def play(self):
        for i in range(self.y):
            print(f"This time you have got: {rd.randint(1,self.z)} points!" )

s1=input('times:')
s2=input('number:')
s=die(int(s1),int(s2))
die.play(s)

        