products = [("Бананы", 120), ("Мясо", 300), ("Яблоки", 80), ("Сыр", 200), ("Молоко", 50)]

expensive_products = filter(lambda product: product[1] > 100, products)

expensive_product_names = list(map(lambda product: product[0], expensive_products))

print(expensive_product_names) 
