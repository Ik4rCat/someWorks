class Product:
    """Класс Товар"""
    
    def __init__(self, name: str, price: float, rating: float):
        """
        Конструктор класса Товар
        :param name: имя товара
        :param price: цена товара
        :param rating: рейтинг товара
        """
        self.name = name
        self.price = price
        self.rating = rating
    
    def __str__(self):
        return f"{self.name} - {self.price} руб. (рейтинг: {self.rating})"
    
    def __repr__(self):
        return f"Product('{self.name}', {self.price}, {self.rating})"


class Category:
    """Класс Категория"""
    
    def __init__(self, name: str):
        """
        Конструктор класса Категория
        :param name: имя категории
        """
        self.name = name
        self.products = []  # массив товаров
    
    def add_product(self, product: Product):
        """Добавить товар в категорию"""
        self.products.append(product)
    
    def __str__(self):
        products_str = "\n  ".join([str(p) for p in self.products])
        return f"Категория: {self.name}\n  {products_str}"
    
    def __repr__(self):
        return f"Category('{self.name}', {len(self.products)} товаров)"


class Basket:
    """Класс Корзина"""
    
    def __init__(self):
        """Конструктор класса Корзина"""
        self.purchased_products = []  # массив купленных товаров
    
    def add_product(self, product: Product):
        """Добавить товар в корзину"""
        self.purchased_products.append(product)
    
    def get_total_price(self) -> float:
        """Получить общую стоимость покупок"""
        return sum(product.price for product in self.purchased_products)
    
    def __str__(self):
        if not self.purchased_products:
            return "Корзина пуста"
        products_str = "\n  ".join([str(p) for p in self.purchased_products])
        total = self.get_total_price()
        return f"Купленные товары:\n  {products_str}\nИтого: {total} руб."
    
    def __repr__(self):
        return f"Basket({len(self.purchased_products)} товаров)"


class User:
    """Класс Пользователь"""
    
    def __init__(self, login: str, password: str):
        """
        Конструктор класса Пользователь
        :param login: логин пользователя
        :param password: пароль пользователя
        """
        self.login = login
        self.password = password
        self.basket = Basket()  # объект класса Basket
    
    def __str__(self):
        return f"Пользователь: {self.login}\n{self.basket}"
    
    def __repr__(self):
        return f"User('{self.login}')"


# Создание товаров
product1 = Product("Ноутбук", 50000.0, 4.5)
product2 = Product("Мышь", 1500.0, 4.2)
product3 = Product("Клавиатура", 3000.0, 4.3)
product4 = Product("Монитор", 25000.0, 4.7)
product5 = Product("Наушники", 5000.0, 4.4)
product6 = Product("Колонки", 8000.0, 4.1)
product7 = Product("Принтер", 15000.0, 4.0)
product8 = Product("Сканер", 12000.0, 3.9)

# Создание категорий и добавление товаров
category1 = Category("Компьютерная техника")
category1.add_product(product1)
category1.add_product(product2)
category1.add_product(product3)
category1.add_product(product4)

category2 = Category("Аудио техника")
category2.add_product(product5)
category2.add_product(product6)

category3 = Category("Офисная техника")
category3.add_product(product7)
category3.add_product(product8)

# Создание пользователей и их покупок
user1 = User("ivanov", "password123")
user1.basket.add_product(product1)
user1.basket.add_product(product2)
user1.basket.add_product(product5)

user2 = User("petrov", "qwerty456")
user2.basket.add_product(product4)
user2.basket.add_product(product6)

user3 = User("sidorov", "abc123")
user3.basket.add_product(product7)
user3.basket.add_product(product3)
user3.basket.add_product(product8)

# Вывод каталога продуктов
print("=" * 50)
print("КАТАЛОГ ПРОДУКТОВ")
print("=" * 50)
print()
print(category1)
print()
print(category2)
print()
print(category3)
print()

# Вывод покупок посетителей магазина
print("=" * 50)
print("ПОКУПКИ ПОСЕТИТЕЛЕЙ МАГАЗИНА")
print("=" * 50)
print()
print(user1)
print()
print(user2)
print()
print(user3)
print()

