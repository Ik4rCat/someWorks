met = float(input("Введите количество метров: "))

# Перевод в сантиметры
cent = met * 100
print(f"{met} метров = {cent} сантиметров")

# Перевод в дециметры
decim = met * 10
print(f"{met} метров = {decim} дециметров")

# Перевод в миллиметры
millimet = met * 1000
print(f"{met} метров = {millimet} миллиметров")

# Перевод в мили
miles = met / 1609.34
print(f"{met} метров = {miles:.2f} миль")