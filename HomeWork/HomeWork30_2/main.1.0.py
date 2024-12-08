num = int(input("Введите число от 1 до 100: "))

if 1 <= num <= 100:
    if num % 3 == 0 and num % 5 == 0:
        print("Fizz Buzz")
    elif num % 3 == 0:
        print("Fizz")
    elif num % 5 == 0:
        print("Buzz")
    else:
        print(num)
else:
    print("Ошибка! Число должно быть в диапазоне от 1 до 100.")
