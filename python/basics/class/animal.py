class Animal(object):
    def __init__(self, age):
        self.age = age
        self.name = None
    def __str__(self):
        return f"I am {self.name} and my age is {self.age}"
    def get_age(self):  
        return self.age
    def set_age(self, newage):
        self.age = newage
    def get_name(self):
        return self.name
    def set_name(self, newname = ""):
        self.name = newname

myanimal = Animal(3)
print(myanimal.get_age())
myanimal.set_name("Kitty")
print(myanimal.__str__())