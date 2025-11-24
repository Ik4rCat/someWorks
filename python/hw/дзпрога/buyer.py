class Buyer:
    
    def __init__(self, last_name="", first_name="", middle_name="", address="", 
                 credit_card_number="", bank_account_number=""):
        self.last_name = last_name
        self.first_name = first_name
        self.middle_name = middle_name
        self.address = address
        self.credit_card_number = credit_card_number
        self.bank_account_number = bank_account_number
    
    def set_last_name(self, last_name):
        self.last_name = last_name
    
    def set_first_name(self, first_name):
        self.first_name = first_name
    
    def set_middle_name(self, middle_name):
        self.middle_name = middle_name
    
    def set_address(self, address):
        self.address = address
    
    def set_credit_card_number(self, credit_card_number):
        self.credit_card_number = credit_card_number
    
    def set_bank_account_number(self, bank_account_number):
        self.bank_account_number = bank_account_number
    
    def get_last_name(self):
        return self.last_name
    
    def get_first_name(self):
        return self.first_name
    
    def get_middle_name(self):
        return self.middle_name
    
    def get_address(self):
        return self.address
    
    def get_credit_card_number(self):
        return self.credit_card_number
    
    def get_bank_account_number(self):
        return self.bank_account_number
    
    def get_full_name(self):
        middle_initial = self.middle_name[0] + "." if self.middle_name else ""
        first_initial = self.first_name[0] + "." if self.first_name else ""
        return f"{self.last_name} {first_initial}{middle_initial}".strip()
    
    def display_info(self):
        print(f"Покупатель: {self.get_full_name()}")
        print(f"Адрес: {self.address}")
        print(f"Номер кредитной карточки: {self.credit_card_number}")
        print(f"Номер банковского счета: {self.bank_account_number}")
        print("-" * 50)
    
    def __str__(self):
        return f"{self.get_full_name()} - {self.credit_card_number}"


def create_buyers_array():
    buyers = [
        Buyer("Иванов", "Иван", "Иванович", "ул. Ленина, 1", "1234567890123456", "40817810099910004312"),
        Buyer("Петров", "Петр", "Петрович", "ул. Пушкина, 10", "2345678901234567", "40817810099910004313"),
        Buyer("Сидоров", "Сидор", "Сидорович", "ул. Гагарина, 5", "3456789012345678", "40817810099910004314"),
        Buyer("Козлов", "Алексей", "Александрович", "ул. Мира, 15", "4567890123456789", "40817810099910004315"),
        Buyer("Смирнов", "Дмитрий", "Сергеевич", "ул. Солнечная, 20", "5678901234567890", "40817810099910004316"),
        Buyer("Васильев", "Василий", "Васильевич", "ул. Центральная, 3", "6789012345678901", "40817810099910004317"),
        Buyer("Антонов", "Антон", "Антонович", "ул. Садовая, 7", "7890123456789012", "40817810099910004318"),
        Buyer("Борисов", "Борис", "Борисович", "ул. Лесная, 12", "8901234567890123", "40817810099910004319")
    ]
    return buyers


def sort_buyers_alphabetically(buyers):
    return sorted(buyers, key=lambda buyer: buyer.last_name)


def filter_buyers_by_card_range(buyers, min_card, max_card):
    filtered = []
    for buyer in buyers:
        try:
            card_number = int(buyer.credit_card_number)
            if min_card <= card_number <= max_card:
                filtered.append(buyer)
        except ValueError:
            continue
    return filtered


def main():
    print("===========================================\n")
    
    buyers = create_buyers_array()
    print(f"Создан массив из {len(buyers)} покупателей\n")
    
    print("1. ВСЕ ПОКУПАТЕЛИ:")
    for i, buyer in enumerate(buyers, 1):
        print(f"{i}. {buyer}")
    print()
    
    sorted_buyers = sort_buyers_alphabetically(buyers)
    print("2. ПОКУПАТЕЛИ В АЛФАВИТНОМ ПОРЯДКЕ:")
    for i, buyer in enumerate(sorted_buyers, 1):
        print(f"{i}. {buyer}")
    print()
    
    min_card = 2000000000000000
    max_card = 5000000000000000
    filtered_buyers = filter_buyers_by_card_range(buyers, min_card, max_card)
    
    print(f"3. ПОКУПАТЕЛИ С НОМЕРАМИ КРЕДИТНЫХ КАРТОЧЕК В ДИАПАЗОНЕ {min_card}-{max_card}:")
    if filtered_buyers:
        for i, buyer in enumerate(filtered_buyers, 1):
            print(f"{i}. {buyer}")
    else:
        print("Покупатели с номерами карточек в указанном диапазоне не найдены.")
    print()
    
    print("4. ДЕТАЛЬНАЯ ИНФОРМАЦИЯ О ПЕРВОМ ПОКУПАТЕЛЕ:")
    if buyers:
        buyers[0].display_info()


main()

