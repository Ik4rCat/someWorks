"""Скрипт 1"""

from random import randint

count = 22
positives = 0
negatives = 0
numbers = []

for i in range(count):
    numbers.append(randint(-50, 50))

for value in numbers:
    if value > 0:
        positives += 1
    elif value < 0:
        negatives += 1

print(f"Массив A({count}): {numbers}")
print(f"Положительных элементов: {positives}")
print(f"Отрицательных элементов: {negatives}")