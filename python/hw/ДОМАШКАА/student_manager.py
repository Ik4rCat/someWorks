class Student:
    def __init__(self, name):
        self.name = name
        self.grades = []
    
    def add_grade(self, grade):
        if Student.is_valid_grade(grade):
            self.grades.append(grade)
            print(f"Оценка {grade} добавлена студенту {self.name}")
            return True
        else:
            print(f"Ошибка: Оценка {grade} недопустима! Оценка должна быть от 1 до 5")
            return False
    
    def get_average_grade(self):
        if not self.grades:
            return 0
        return sum(self.grades) / len(self.grades)
    
    def display_info(self):
        avg_grade = self.get_average_grade()
        print(f"Студент: {self.name}")
        print(f"Оценки: {self.grades}")
        print(f"Средняя оценка: {avg_grade:.2f}")
        print("-" * 30)
    
    @staticmethod
    def is_valid_grade(grade):
        try:
            grade = int(grade)
            return 1 <= grade <= 5
        except (ValueError, TypeError):
            return False
    
    @classmethod
    def calculate_class_average(cls, students):
        if not students:
            return 0
        
        all_grades = []
        for student in students:
            all_grades.extend(student.grades)
        
        if not all_grades:
            return 0
        
        return sum(all_grades) / len(all_grades)


class StudentManager:
    def __init__(self):
        self.students = []
    
    def add_student(self, name):
        student = Student(name)
        self.students.append(student)
        print(f"Студент {name} добавлен в систему")
        return student
    
    def find_student(self, name):
        for student in self.students:
            if student.name.lower() == name.lower():
                return student
        return None
    
    def add_grade_to_student(self, name, grade):
        student = self.find_student(name)
        if student:
            return student.add_grade(grade)
        else:
            print(f"Студент {name} не найден!")
            return False
    
    def display_student_average(self, name):
        student = self.find_student(name)
        if student:
            student.display_info()
        else:
            print(f"Студент {name} не найден!")
    
    def display_class_average(self):
        if not self.students:
            print("В системе нет студентов!")
            return
        
        avg = Student.calculate_class_average(self.students)
        print(f"Средняя оценка всех студентов: {avg:.2f}")
        print(f"Всего студентов: {len(self.students)}")
        print("-" * 30)
    
    def display_all_students(self):
        if not self.students:
            print("В системе нет студентов!")
            return
        
        print("=== ИНФОРМАЦИЯ О ВСЕХ СТУДЕНТАХ ===")
        for student in self.students:
            student.display_info()
    
    def check_grade_validity(self, grade):
        if Student.is_valid_grade(grade):
            print(f"Оценка {grade} допустима (от 1 до 5)")
        else:
            print(f"Оценка {grade} недопустима! Оценка должна быть от 1 до 5")


def main():
    manager = StudentManager()
    
    while True:
        print("\n" + "="*50)
        print("СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ")
        print("="*50)
        print("1. Добавить нового студента")
        print("2. Добавить оценку студенту")
        print("3. Вывести среднюю оценку студента")
        print("4. Вывести среднюю оценку всех студентов")
        print("5. Проверить допустимость оценки")
        print("6. Показать всех студентов")
        print("7. Выход")
        print("-"*50)
        
        try:
            choice = input("Выберите действие (1-7): ").strip()
            
            if choice == "1":
                name = input("Введите имя студента: ").strip()
                if name:
                    manager.add_student(name)
                else:
                    print("Имя не может быть пустым!")
            
            elif choice == "2":
                name = input("Введите имя студента: ").strip()
                if name:
                    try:
                        grade = int(input("Введите оценку (1-5): "))
                        manager.add_grade_to_student(name, grade)
                    except ValueError:
                        print("Ошибка: Введите числовое значение для оценки!")
                else:
                    print("Имя не может быть пустым!")
            
            elif choice == "3":
                name = input("Введите имя студента: ").strip()
                if name:
                    manager.display_student_average(name)
                else:
                    print("Имя не может быть пустым!")
            
            elif choice == "4":
                manager.display_class_average()
            
            elif choice == "5":
                try:
                    grade = int(input("Введите оценку для проверки: "))
                    manager.check_grade_validity(grade)
                except ValueError:
                    print("Ошибка: Введите числовое значение для оценки!")
            
            elif choice == "6":
                manager.display_all_students()
            
            elif choice == "7":
                print("До свидания!")
                break
            
            else:
                print("Неверный выбор! Пожалуйста, выберите от 1 до 7.")
        
        except KeyboardInterrupt:
            print("\n\nПрограмма прервана пользователем. До свидания!")
            break
        except Exception as e:
            print(f"Произошла ошибка: {e}")



main()
