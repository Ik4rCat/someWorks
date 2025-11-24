from student_manager import Student, StudentManager

def demo():
    print("=== ДЕМОНСТРАЦИЯ ПРОГРАММЫ УПРАВЛЕНИЯ СТУДЕНТАМИ ===\n")
    
    manager = StudentManager()
    
    print("1. Добавляем студентов:")
    manager.add_student("Иван Петров")
    manager.add_student("Мария Сидорова")
    manager.add_student("Алексей Козлов")
    print()
    
    print("2. Добавляем оценки студентам:")
    manager.add_grade_to_student("Иван Петров", 5)
    manager.add_grade_to_student("Иван Петров", 4)
    manager.add_grade_to_student("Иван Петров", 5)
    
    manager.add_grade_to_student("Мария Сидорова", 3)
    manager.add_grade_to_student("Мария Сидорова", 4)
    manager.add_grade_to_student("Мария Сидорова", 5)
    manager.add_grade_to_student("Мария Сидорова", 4)
    
    manager.add_grade_to_student("Алексей Козлов", 2)
    manager.add_grade_to_student("Алексей Козлов", 3)
    manager.add_grade_to_student("Алексей Козлов", 4)
    print()
    
    print("3. Пытаемся добавить недопустимую оценку:")
    manager.add_grade_to_student("Иван Петров", 6)
    manager.add_grade_to_student("Иван Петров", 0)
    print()
    
    print("4. Проверяем допустимость оценок:")
    Student.is_valid_grade(5)
    Student.is_valid_grade(6)
    Student.is_valid_grade(0)
    print()
    
    print("5. Средние оценки студентов:")
    manager.display_student_average("Иван Петров")
    manager.display_student_average("Мария Сидорова")
    manager.display_student_average("Алексей Козлов")
    print()
    
    print("6. Средняя оценка всех студентов:")
    manager.display_class_average()
    print()
    
    print("7. Информация о всех студентах:")
    manager.display_all_students()
    
    print("8. Создаем нового менеджера и проверяем пустой список:")
    empty_manager = StudentManager()
    empty_manager.display_class_average()
    empty_manager.display_all_students()


demo()
