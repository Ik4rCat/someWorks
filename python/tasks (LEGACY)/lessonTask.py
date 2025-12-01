import random, math
global_randnumX = random.randint(1,10)
global_randnumY = random.randint(1,10)


class Employee:
    
    def __init__(self, fname, lname, salary, department):
        self.fname = "sampleFirstName"
        self.lname = "SampleLastName"
        self.salary = 0
        self.department = "none"


class Manager(Employee):

    def __init__(self, assignedDepartment, level=["junior","senior"]):
        self.assignedDepartment = "none"
        self.level = level[0]

class Developer(Employee):

    def __init__(self, stack, level=["junior","middle","senior"]):
        self.stack = "empty"
        self.level = level[0]


class Shape: 
    def __init__(self, x=0, y=0, z=0, r=0):
        self.x = x
        self.y = y
        self.z = z

class Rectamgle(Shape):
    def __init__(self, a=global_randnumX, b=global_randnumY):
        self.a = a
        self.b = b
        self.c = a
        self.d = b

    def PERim(self):
        P = 2 * (self.a + self.b)
        print(P)


class Circle(Shape):
    def __init__(self, l=global_randnumX):
        self.l = l
        self.r = l/2
        
    def Plosh(self):
        S = math.pi * self.r**2
        print(S)

