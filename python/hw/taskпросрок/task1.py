class TriangleChecker:
    def __init__(self):
        self.a = None
        self.b = None
        self.c = None

    def input_sides(self):

        try:
            self.a = float(input("Write first num: "))
            self.b = float(input("Write second num: "))
            self.c = float(input("Write third num: "))
            return True
        except ValueError:
            return False

    def is_triangle(self):
        sides = [self.a, self.b, self.c]
        
        if not all(isinstance(side, (int, float)) for side in sides):
            return '[!] You need to write numbers only!'
        
        if any(side <= 0 for side in sides):
            return '[!] Nothing will work with negative numbers!'

        if (self.a + self.b > self.c and 
            self.a + self.c > self.b and 
            self.b + self.c > self.a):
            return '[@] Yay, you can build a Triangle!'
        
        return '[#] Its a pity, but you cant make a triangle out of this.'

    def main(self):
        if self.input_sides():
            result = self.is_triangle()
            print(result)
        else:
            print('[!] You need to write numbers only!')

checker = TriangleChecker()
checker.main()


        