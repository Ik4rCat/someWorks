num = float(input("Введите число: "))

while True:
    power = int(input("Введите степень (от 0 до 7): "))

    if 0 <= power <= 7:
        result = num ** power
        print(f"{num} в степени {power} равно {result}")
        break 
    else:
        print("Ошибка! Степень должна быть в диапазоне от 0 до 7.")