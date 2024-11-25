import math

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius ** 2

    def set_diameter(self, diameter):
        self.radius = diameter / 2

circle = Circle(5)
circle.set_diameter(10) 
print(circle.area()) 
