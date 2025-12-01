import random

first_names = ["Ethan", "Olivia", "Liam", 
               "Sophia", "Noah", "Emma", 
               "Jackson", "Ava", "Oliver",
                "Isabella", "Mateo", "Chloe", 
                "Benjamin", "Scarlett", "Grayson"]

last_names = ["Smith", "Jones", "Brown", 
              "Taylor", "Wilson", "Garcia", 
              "Anderson", "Martinez", "Davis", 
              "Rodriguez", "Miller", "Williams", 
              "Thompson", "Evans", "Hall"]

staff = ["Software Engineer","Data Scientist","Cybersecurity Analyst"]

class Employee:

    def __init__(self, first_name, last_name, position, salary):
        self.first_name = first_name
        self.last_name = last_name
        self.position = position
        self.salary = salary

    def TakeInfoAbout(first_name, last_name, position):
        
        return (f"[&] Cотрудник: {first_name} {last_name}, должность: {position}")

    def AboutSalary(emp, salary):
        return (f"[$] Зарплата сотрудника {emp}: {salary}")

# class Manager(Employee):


# class Intern(Employee):

    