"""Скрипт 3"""

count = 18

while True:
    data = input(f"Введите {count} чисел для массива A: ").split()
    if len(data) != count:
        print("Нужно ровно 18 значений.")
        continue
    try:
        numbers = [float(x) for x in data]
        break
    except ValueError:
        print("Все элементы должны быть числами.")

total = sum(value for value in numbers if value > 0 and value % 2 == 0)
print(f"Сумма чётных положительных элементов: {total}")
