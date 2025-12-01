import random

student_name = []
grade = []

def print_section(title: str):
    bar = "=" * len(title)
    print(f"\n{title}\n{bar}")


def safe_input(prompt: str) -> str:
    try:
        return input(prompt)
    except Exception:
        return ""

class Students:

    def __init__(self,name,grades):
        self.name = name
        self.grades = []

def RandomTime():
        for i in range(20):
            g = random.randrange(1,6)
            grade.append(g)

def main():
    print_section("Welcome!")
    print("1) вывести всех учеников")
    print("2) ")
    print("0) Выход")

# class Classroom:
    