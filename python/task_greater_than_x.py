"""Скрипт 2"""

count = 40

while True:
    data = input(f"Введите {count} чисел для массива M: ").split()
    if len(data) != count:
        print("Нужно ровно 40 значений, попробуйте снова.")
        continue
    try:
        numbers = [float(x) for x in data]
        break
    except ValueError:
        print("Все элементы должны быть числами.")

while True:
    raw = input("Введите число X: ").strip()
    try:
        threshold = float(raw)
        break
    except ValueError:
        print("X должно быть числом.")

count = sum(1 for value in numbers if value > threshold)
print(f"Количество элементов больше {threshold}: {count}")