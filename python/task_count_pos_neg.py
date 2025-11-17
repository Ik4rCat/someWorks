"""Скрипт 1"""

from random import randint

cnt = 22
poss = 0
negs = 0
A = []

for i in range(cnt):
    A.append(randint(-50, 50))

for value in A:
    if value > 0:
        poss += 1
    elif value < 0:
        negs += 1

print(f"Массив A({cnt}): {A}")
print(f"Положительных элементов: {poss}")
print(f"Отрицательных элементов: {negs}")