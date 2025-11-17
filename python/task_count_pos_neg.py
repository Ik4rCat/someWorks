"""Скрипт 1"""

count = 22

while True:
    data = input(f"Введите {count} чисел для массива A: ").split()
    if len(data) != count:
        print("Неверное количество значений, попробуйте снова.")
        continue
    try:
        numbers = [float(x) for x in data]
        break
    except ValueError:
        print("Все элементы должны быть числами, попробуйте снова.")

positives = sum(1 for value in numbers if value > 0)
negatives = sum(1 for value in numbers if value < 0)

print(f"Положительных элементов: {positives}")
print(f"Отрицательных элементов: {negatives}")