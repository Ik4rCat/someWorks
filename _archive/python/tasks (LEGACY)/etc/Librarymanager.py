class Students:
    def __init__(self, name):
        self.name = name
        self.grades = []

    def add_grade(self, grade):
        self.grades.append(grade)

    def awarage_grade(self):
        if self.grades:
            return sum(self.grades) / len(self.grades)
        return 0.0
    

class Classroom:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def add_grade_to_student(self, name, grade):
        for student in self.students:
            if student.name == name:
                student.add_grade