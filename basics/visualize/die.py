from random import randint


class Die:
    def __init__(self, sides=6):
        self.sides = sides

    def roll_num(self):
        return randint(1, self.sides)     # random.randint(a, b) returns a random integer between a and b (inclusive)    



