"""Скрипт 3"""

from random import randint

cnt = 40
grtr = 0
M = []

for i in range(cnt):
    M.append(randint(-100, 100))

print(f"Массив M({cnt}): {M}")

while True:
    raw = input("Введите число X: ").strip()
    try:
        thrshld = float(raw)
        break
    except ValueError:
        print("X должно быть числом.")

for value in M:
    if value > thrshld:
        grtr += 1

print(f"Количество элементов больше {thrshld}: {grtr}")