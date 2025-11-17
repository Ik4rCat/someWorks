"""Скрипт 2"""

from random import randint

cnt = 18
ttl = 0
A = []

for i in range(cnt):
    A.append(randint(-50, 50))


for value in A:
    if value > 0 and value % 2 == 0:
        ttl += value

print(f"Массив A({cnt}): {A}")
print(f"Сумма чётных положительных элементов: {ttl}")
