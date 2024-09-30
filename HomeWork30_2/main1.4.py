def calculate_salary(sales):
    base_salary = 200
    bonus = 0

    if sales <= 500:
        bonus = sales * 0.03
    elif sales <= 1000:
        bonus = 500 * 0.03 + (sales - 500) * 0.05
    else:
        bonus = 500 * 0.03 + 500 * 0.05 + (sales - 1000) * 0.08

    return base_salary + bonus

managers = []
for i in range(3):
    sales = float(input(f"Введите уровень продаж менеджера {i+1}: "))
    salary = calculate_salary(sales)
    managers.append({"name": f"Менеджер {i+1}", "sales": sales, "salary": salary})

best_manag= max(managers, key=lambda x: x["salary"])

best_manag["salary"] += 200

print("Результаты:")
for manager in managers:
    print(f"{manager['name']} - Продажи: {manager['sales']}$ - Зарплата: {manager['salary']}$")

print(f"\nЛучший менеджер: {best_manag['name']} - Зарплата: {best_manag['salary']}$")