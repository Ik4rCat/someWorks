employees = [("Иван", 25, "инженер"), ("Анна", 32, "менеджер"), ("Борис", 45, "директор"), ("Мария", 28, "аналитик")]

filtered_employees = filter(lambda employee: employee[1] > 30, employees)

sorted_employees = sorted(filtered_employees, key=lambda employee: employee[0])

print(sorted_employees) 
