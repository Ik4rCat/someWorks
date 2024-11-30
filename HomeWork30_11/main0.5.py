products = {}
for _ in range(3):
    product_name = input("Введите название продукта: ")
    product_price = int(input("Введите его стоимость: "))
    products[product_name] = product_price

product_to_buy = input("Какой продукт вы хотите купить? ")
price = products.get(product_to_buy)

if price is not None:
    print(f"Стоимость {product_to_buy}: {price}")
else:
    print(f"Продукт {product_to_buy} не найден.")
