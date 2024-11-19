students = [("Алексей", 19), ("Мария", 21), ("Дмитрий", 22), ("Ольга", 20)]

filtered_students = filter(lambda student: student[1] > 20, students)

result = list(map(lambda student: student[0], filtered_students))

print(result) 
