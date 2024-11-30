grades = {
    "математика": 5,
    "физика": 4,
    "информатика": 5,
    "химия": 3
}

# Вычисление среднего балла
average_grade = sum(grades.values()) / len(grades)
print(f"Средний балл: {average_grade:.2f}")

# Нахождение предмета с наивысшей оценкой
best_subject = max(grades.items(), key=lambda x: x[1])[0]
print(f"Лучшая оценка по предмету: {best_subject}")
