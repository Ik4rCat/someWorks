class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    @property
    def width(self):
        return self._width
    
    @width.setter
    def width(self, value):
        if value > 0:
            self._width = value
        else:
            raise ValueError("Ширина должна быть положительным числом.")
    
    @property
    def height(self):
        return self._height
    
    @height.setter
    def height(self, value):
        if value > 0:
            self._height = value
        else:
            raise ValueError("Высота должна быть положительным числом.")

    def area(self):
        return self._width * self._height

rect = Rectangle(10, 5)
rect.width = 15
print(rect.area())
