class Coordinate(object):
    def __init__ (self, xval, yval):
        self.x = xval
        self.y = yval
    def distance(self, other):
        return ((self.x - other.x)**2 + (self.y - other.y)**2)**0.5


c = Coordinate(3, 4)
b = Coordinate(5, 6)
m = list[2,3]
print(c.distance(b))
#print(c.distance(c))
print(Coordinate.distance(c, b))
#print(c.distance(b))
#print(c.x)
#print(c.y)

class Circle(object):
    def __init__ (self, center, radius):
        self.center = center
        self.radius = radius
center = Coordinate(2,2)
my_circle = Circle(center, 2)