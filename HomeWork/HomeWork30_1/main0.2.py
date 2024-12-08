num = int(input("Введите четырехзначное число: "))

git1 = num // 1000
git2 = (num % 1000) // 100
git3 = (num % 100) // 10
git4 = num % 10

product = git1 * git2 * git3 * git4

print(f"Произведение цифр числа {num} равно: {product}")