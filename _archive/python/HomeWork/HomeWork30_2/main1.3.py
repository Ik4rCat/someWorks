operator_prices = {
    "МТС": {"МТС": 1, "Билайн": 2, "Мегафон": 3, "Tele2": 4},
    "Билайн": {"МТС": 2, "Билайн": 1, "Мегафон": 4, "Tele2": 3},
    "Мегафон": {"МТС": 3, "Билайн": 4, "Мегафон": 1, "Tele2": 2},
    "Tele2": {"МТС": 4, "Билайн": 3, "Мегафон": 2, "Tele2": 1}
}

call_duration = float(input("Введите продолжительность разговора (в минутах): "))

while True:
    calling_operator = input("Введите оператора, с которого звонят (МТС, Билайн, Мегафон, Tele2): ").upper()
    receiving_operator = input("Введите оператора, которому звонят (МТС, Билайн, Мегафон, Tele2): ").upper()

    if calling_operator in operator_prices and receiving_operator in operator_prices:
        call_cost = call_duration * operator_prices[calling_operator][receiving_operator]
        print(f"Стоимость разговора: {call_cost} рублей")
        break
    else:
        print("Ошибка! Введены неверные операторы.")
