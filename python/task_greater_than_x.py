"""Скрипт 2"""

from random import randint

count = 40
greater = 0
numbers = []

for i in range(count):
    numbers.append(randint(-100, 100))

print(f"Массив M({count}): {numbers}")

while True:
    raw = input("Введите число X: ").strip()
    try:
        threshold = float(raw)
        break
    except ValueError:
        print("X должно быть числом.")

for value in numbers:
    if value > threshold:
        greater += 1

print(f"Количество элементов больше {threshold}: {greater}")