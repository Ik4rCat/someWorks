"""Скрипт 3"""

from random import randint

count = 18
total = 0
numbers = []

for i in range(count):
    numbers.append(randint(-50, 50))


for value in numbers:
    if value > 0 and value % 2 == 0:
        total += value

print(f"Массив A({count}): {numbers}")
print(f"Сумма чётных положительных элементов: {total}")
