class Vehicle:
    
    def __init__(self, brand, model, year, price):
        self.brand = brand
        self.model = model
        self.year = year
        self.price = price
    
    def display_info(self):
        print(f"=== Информация о транспортном средстве ===")
        print(f"Марка: {self.brand}")
        print(f"Модель: {self.model}")
        print(f"Год выпуска: {self.year}")
        print(f"Стоимость: {self.price:,.2f} руб.")
        print("-" * 40)
    
    def get_age(self):
        from datetime import datetime
        current_year = datetime.now().year
        return current_year - self.year
    
    def apply_discount(self, discount_percent):
        if 0 <= discount_percent <= 100:
            self.price = self.price * (1 - discount_percent / 100)
            print(f"Применена скидка {discount_percent}%. Новая цена: {self.price:,.2f} руб.")
        else:
            print("Неверный процент скидки. Допустимый диапазон: 0-100%")


class Car(Vehicle):
    
    def __init__(self, brand, model, year, price, body_type, engine_volume, fuel_type):
        super().__init__(brand, model, year, price)
        self.body_type = body_type
        self.engine_volume = engine_volume
        self.fuel_type = fuel_type
    
    def display_info(self):
        print(f"=== Легковой автомобиль ===")
        print(f"Марка: {self.brand}")
        print(f"Модель: {self.model}")
        print(f"Год выпуска: {self.year}")
        print(f"Тип кузова: {self.body_type}")
        print(f"Объем двигателя: {self.engine_volume} л")
        print(f"Тип топлива: {self.fuel_type}")
        print(f"Стоимость: {self.price:,.2f} руб.")
        print(f"Возраст: {self.get_age()} лет")
        print("-" * 40)
    
    def calculate_tax(self):
        base_rate = 10
        if self.engine_volume <= 1.0:
            rate = base_rate * 0.5
        elif self.engine_volume <= 1.5:
            rate = base_rate * 0.8
        elif self.engine_volume <= 2.0:
            rate = base_rate
        else:
            rate = base_rate * 1.5
        
        power = self.engine_volume * 100
        return power * rate


class Motorcycle(Vehicle):
    
    def __init__(self, brand, model, year, price, engine_type, displacement):
        super().__init__(brand, model, year, price)
        self.engine_type = engine_type
        self.displacement = displacement
    
    def display_info(self):
        print(f"=== Мотоцикл ===")
        print(f"Марка: {self.brand}")
        print(f"Модель: {self.model}")
        print(f"Год выпуска: {self.year}")
        print(f"Тип двигателя: {self.engine_type}")
        print(f"Рабочий объем: {self.displacement} куб.см")
        print(f"Стоимость: {self.price:,.2f} руб.")
        print(f"Возраст: {self.get_age()} лет")
        print("-" * 40)
    
    def get_category(self):
        if self.displacement < 125:
            return "Легкий мотоцикл"
        elif self.displacement < 400:
            return "Средний мотоцикл"
        elif self.displacement < 750:
            return "Тяжелый мотоцикл"
        else:
            return "Спортбайк/Круизер"


class Truck(Vehicle):
    
    def __init__(self, brand, model, year, price, load_capacity, fuel_consumption):
        super().__init__(brand, model, year, price)
        self.load_capacity = load_capacity
        self.fuel_consumption = fuel_consumption
    
    def display_info(self):
        print(f"=== Грузовой автомобиль ===")
        print(f"Марка: {self.brand}")
        print(f"Модель: {self.model}")
        print(f"Год выпуска: {self.year}")
        print(f"Грузоподъемность: {self.load_capacity} т")
        print(f"Расход топлива: {self.fuel_consumption} л/100км")
        print(f"Стоимость: {self.price:,.2f} руб.")
        print(f"Возраст: {self.get_age()} лет")
        print("-" * 40)
    
    def calculate_operating_cost(self, distance_km):
        fuel_price = 50
        fuel_needed = (distance_km / 100) * self.fuel_consumption
        return fuel_needed * fuel_price


class VehicleManager:
    
    def __init__(self):
        self.vehicles = []
        self.cars = []
        self.motorcycles = []
        self.trucks = []
        self.initialize_vehicles()
    
    def initialize_vehicles(self):
        self.cars = [
            Car("Toyota", "Camry", 2022, 2500000, "седан", 2.5, "бензин"),
            Car("BMW", "X5", 2023, 4500000, "внедорожник", 3.0, "бензин"),
            Car("Tesla", "Model 3", 2023, 3500000, "седан", 0, "электро"),
            Car("Audi", "A4", 2021, 2800000, "седан", 2.0, "бензин"),
            Car("Mercedes", "C-Class", 2022, 3200000, "седан", 1.5, "бензин")
        ]
        
        self.motorcycles = [
            Motorcycle("Honda", "CBR600RR", 2021, 800000, "4-тактный", 599),
            Motorcycle("Yamaha", "R1", 2023, 1200000, "4-тактный", 998),
            Motorcycle("Kawasaki", "Ninja 400", 2022, 450000, "4-тактный", 399),
            Motorcycle("Ducati", "Panigale V4", 2023, 2500000, "4-тактный", 1103),
            Motorcycle("Suzuki", "GSX-R750", 2021, 900000, "4-тактный", 749)
        ]
        
        self.trucks = [
            Truck("Kamaz", "5320", 2020, 3500000, 8.0, 25.0),
            Truck("MAN", "TGX", 2022, 5500000, 12.0, 30.0),
            Truck("Volvo", "FH16", 2023, 6500000, 15.0, 35.0),
            Truck("Scania", "R500", 2021, 4800000, 10.0, 28.0),
            Truck("Iveco", "Stralis", 2020, 4200000, 9.0, 26.0)
        ]
        
        self.vehicles = self.cars + self.motorcycles + self.trucks
    
    def show_main_menu(self):
        while True:
            print("\n" + "="*50)
            print("    CRM СИСТЕМА АВТОСАЛОНА")
            print("="*50)
            print("1. Просмотреть легковые автомобили")
            print("2. Просмотреть мотоциклы")
            print("3. Просмотреть грузовые автомобили")
            print("4. Просмотреть все транспортные средства")
            print("5. Поиск по марке")
            print("6. Статистика")
            print("0. Выход")
            print("="*50)
            
            choice = input("Выберите пункт меню (0-6): ")
            
            if choice == "1":
                self.show_cars()
            elif choice == "2":
                self.show_motorcycles()
            elif choice == "3":
                self.show_trucks()
            elif choice == "4":
                self.show_all_vehicles()
            elif choice == "5":
                self.search_by_brand()
            elif choice == "6":
                self.show_statistics()
            elif choice == "0":
                print("До свидания!")
                break
            else:
                print("Неверный выбор. Попробуйте снова.")
    
    def show_cars(self):
        print(f"\n=== ЛЕГКОВЫЕ АВТОМОБИЛИ ({len(self.cars)} шт.) ===")
        for i, car in enumerate(self.cars, 1):
            print(f"\n{i}. {car.brand} {car.model} ({car.year})")
            print(f"   Тип кузова: {car.body_type}")
            print(f"   Двигатель: {car.engine_volume}л, {car.fuel_type}")
            print(f"   Цена: {car.price:,.2f} руб.")
            print(f"   Возраст: {car.get_age()} лет")
            print(f"   Налог: {car.calculate_tax():.2f} руб.")
    
    def show_motorcycles(self):
        print(f"\n=== МОТОЦИКЛЫ ({len(self.motorcycles)} шт.) ===")
        for i, motorcycle in enumerate(self.motorcycles, 1):
            print(f"\n{i}. {motorcycle.brand} {motorcycle.model} ({motorcycle.year})")
            print(f"   Двигатель: {motorcycle.engine_type}, {motorcycle.displacement} куб.см")
            print(f"   Цена: {motorcycle.price:,.2f} руб.")
            print(f"   Возраст: {motorcycle.get_age()} лет")
            print(f"   Категория: {motorcycle.get_category()}")
    
    def show_trucks(self):
        print(f"\n=== ГРУЗОВЫЕ АВТОМОБИЛИ ({len(self.trucks)} шт.) ===")
        for i, truck in enumerate(self.trucks, 1):
            print(f"\n{i}. {truck.brand} {truck.model} ({truck.year})")
            print(f"   Грузоподъемность: {truck.load_capacity} т")
            print(f"   Расход топлива: {truck.fuel_consumption} л/100км")
            print(f"   Цена: {truck.price:,.2f} руб.")
            print(f"   Возраст: {truck.get_age()} лет")
            cost_500km = truck.calculate_operating_cost(500)
            print(f"   Стоимость на 500км: {cost_500km:.2f} руб.")
    
    def show_all_vehicles(self):
        print(f"\n=== ВСЕ ТРАНСПОРТНЫЕ СРЕДСТВА ({len(self.vehicles)} шт.) ===")
        for i, vehicle in enumerate(self.vehicles, 1):
            vehicle_type = type(vehicle).__name__
            print(f"\n{i}. [{vehicle_type}] {vehicle.brand} {vehicle.model} ({vehicle.year})")
            print(f"   Цена: {vehicle.price:,.2f} руб.")
            print(f"   Возраст: {vehicle.get_age()} лет")
    
    def search_by_brand(self):
        brand = input("\nВведите марку для поиска: ").strip()
        if not brand:
            print("Марка не может быть пустой!")
            return
        
        found_vehicles = []
        for vehicle in self.vehicles:
            if brand.lower() in vehicle.brand.lower():
                found_vehicles.append(vehicle)
        
        if found_vehicles:
            print(f"\n=== НАЙДЕНО {len(found_vehicles)} ТРАНСПОРТНЫХ СРЕДСТВ МАРКИ '{brand.upper()}' ===")
            for i, vehicle in enumerate(found_vehicles, 1):
                vehicle_type = type(vehicle).__name__
                print(f"\n{i}. [{vehicle_type}] {vehicle.brand} {vehicle.model} ({vehicle.year})")
                print(f"   Цена: {vehicle.price:,.2f} руб.")
                print(f"   Возраст: {vehicle.get_age()} лет")
        else:
            print(f"Транспортные средства марки '{brand}' не найдены.")
    
    def show_statistics(self):
        print("\n=== СТАТИСТИКА АВТОСАЛОНА ===")
        print(f"Всего транспортных средств: {len(self.vehicles)}")
        print(f"Легковых автомобилей: {len(self.cars)}")
        print(f"Мотоциклов: {len(self.motorcycles)}")
        print(f"Грузовых автомобилей: {len(self.trucks)}")
        
        if self.vehicles:
            total_value = sum(vehicle.price for vehicle in self.vehicles)
            avg_price = total_value / len(self.vehicles)
            print(f"\nОбщая стоимость: {total_value:,.2f} руб.")
            print(f"Средняя цена: {avg_price:,.2f} руб.")
            
            min_price = min(vehicle.price for vehicle in self.vehicles)
            max_price = max(vehicle.price for vehicle in self.vehicles)
            print(f"Минимальная цена: {min_price:,.2f} руб.")
            print(f"Максимальная цена: {max_price:,.2f} руб.")
            
            current_year = 2024
            new_vehicles = [v for v in self.vehicles if v.year >= current_year - 2]
            print(f"Новых машин (2022+): {len(new_vehicles)}")


if __name__ == "__main__":
    manager = VehicleManager()
    
    print("=== ДЕМОНСТРАЦИЯ CRM СИСТЕМЫ АВТОСАЛОНА ===")
    print("Система готова к работе! Доступны следующие функции:")
    print("1. Просмотр легковых автомобилей")
    print("2. Просмотр мотоциклов") 
    print("3. Просмотр грузовых автомобилей")
    print("4. Просмотр всех транспортных средств")
    print("5. Поиск по марке")
    print("6. Статистика")
    print("\nДемонстрация работы системы:")
    
    print("\n" + "="*50)
    print("ДЕМОНСТРАЦИЯ: Просмотр легковых автомобилей")
    print("="*50)
    manager.show_cars()
    
    print("\n" + "="*50)
    print("ДЕМОНСТРАЦИЯ: Просмотр мотоциклов")
    print("="*50)
    manager.show_motorcycles()
    
    print("\n" + "="*50)
    print("ДЕМОНСТРАЦИЯ: Поиск по марке 'BMW'")
    print("="*50)
    found_vehicles = []
    for vehicle in manager.vehicles:
        if 'bmw' in vehicle.brand.lower():
            found_vehicles.append(vehicle)
    
    if found_vehicles:
        print(f"\n=== НАЙДЕНО {len(found_vehicles)} ТРАНСПОРТНЫХ СРЕДСТВ МАРКИ 'BMW' ===")
        for i, vehicle in enumerate(found_vehicles, 1):
            vehicle_type = type(vehicle).__name__
            print(f"\n{i}. [{vehicle_type}] {vehicle.brand} {vehicle.model} ({vehicle.year})")
            print(f"   Цена: {vehicle.price:,.2f} руб.")
            print(f"   Возраст: {vehicle.get_age()} лет")
    else:
        print("Транспортные средства марки 'BMW' не найдены.")
    
    print("\n" + "="*50)
    print("ДЕМОНСТРАЦИЯ: Статистика")
    print("="*50)
    manager.show_statistics()
    
    print("\n" + "="*50)
    print("Для интерактивного режима запустите:")
    print("python -c \"from vehicle_crm import VehicleManager; VehicleManager().show_main_menu()\"")
    print("="*50)
