import re

TEXT = """Дата: 14 января 2026 года.
Продаётся просторная трёхкомнатная квартира в престижном районе!
Предлагаем к приобретению светлую и уютную трёхкомнатную квартиру общей площадью 85 м² в динамично развивающемся районе города. Квартира расположена на 7‑м этаже 12‑этажного дома, построенного по современному проекту.
Основные характеристики:
    • общая площадь: 85 м²;
    • жилая площадь: 52 м²;
    • кухня: 12 м²;
    • высокие потолки: 2,8 м;
    • два санузла (раздельный);
    • застеклённая лоджия.
Преимущества объекта:
    • качественная предчистовая отделка;
    • просторные комнаты правильной формы;
    • большие окна с видом на благоустроенную территорию;
    • развитая инфраструктура: в шаговой доступности школа, детский сад, поликлиника, супермаркеты и парк;
    • подземный паркинг и консьерж в доме.
Стоимость: 8 500 000 рублей. Возможен обоснованный торг.
Для просмотра квартиры и обсуждения условий покупки звоните:
    • +7 (916) 123‑45‑67 (Анна, риелтор);
    • +7 (926) 789‑01‑23 (Сергей, владелец).
Будем рады ответить на ваши вопросы и организовать показ в удобное для вас время!
Адрес:  Самара, Арсенальная, 56, 234. 
Дата: 14 января 2026 года.
Уважаемые коллеги!
Приглашаем вас принять участие в ежегодном корпоративном мероприятии нашей компании, которое состоится 25 января 2026 года в 18:00 в ресторане «Гранд Палас» (Пермь,  Центральная, 45).
Тема вечера: «Достижения и перспективы: подводим итоги года и строим планы».
Программа мероприятия:
    1. Торжественное открытие и приветственное слово генерального директора.
    2. Награждение лучших сотрудников по итогам года.
    3. Фуршет и развлекательная программа.
    4. Неофициальная часть с живой музыкой и танцами.
Важные детали:
    • форма одежды: деловой кэжуал или вечерний наряд;
    • количество гостей: просим подтвердить участие до 20 января 2026 года;
    • парковка: предусмотрена бесплатная парковка для гостей у ресторана.
Для подтверждения вашего участия и уточнения деталей обращайтесь по телефонам:
    • +7 (903) 456‑78‑90 (Елена, отдел кадров);
    • +7 (999) 012‑34‑56 (Михаил, организатор мероприятия).
Мы ценим ваш труд и вклад в развитие компании и будем рады видеть вас на празднике!
С уважением,
Администрация компании «ТехноПрогресс»"""

MONTHS = {
    'января': 1, 'февраля': 2, 'марта': 3, 'апреля': 4, 'мая': 5, 'июня': 6,
    'июля': 7, 'августа': 8, 'сентября': 9, 'октября': 10, 'ноября': 11, 'декабря': 12
}


def task1_dates():
    pattern = r'(\d{1,2})\s+(января|февраля|марта|апреля|мая|июня|июля|августа|сентября|октября|ноября|декабря)\s+(\d{4})\s+года'
    matches = re.findall(pattern, TEXT)
    result = []
    for day, month_name, year in matches:
        month = MONTHS.get(month_name, 0)
        result.append(f"{day}.{month}.{year}")
    return result, len(result)


def task2_numbers_with_m():
    pattern = r'\d+(?:[.,]\d+)?\s*[‑\-]?\s*м'
    matches = re.finditer(pattern, TEXT)
    result = []
    for m in matches:
        result.append((m.group(), m.start()))
    return result


def task3_phone_validation():
    phones = re.findall(r'\+\d[\s\d\-‑()]*\d', TEXT)
    result = []
    for phone in phones:
        clean = re.sub(r'\D', '', phone)
        is_valid = len(clean) == 11 and clean.startswith('79')
        result.append((phone.strip(), is_valid))
    return result


def task4_uppercase_words():
    words = re.findall(r'[а-яА-Яa-zA-ZёЁ]+', TEXT)
    count = sum(1 for w in words if any(c.isupper() for c in w))
    return count


def task5_address():
    pattern = r'Адрес:\s*([^,]+),\s*([^,]+),\s*(\d+)(?:,\s*(\d+))?\.'
    match = re.search(pattern, TEXT)
    if match:
        city, street, house, apt = match.group(1).strip(), match.group(2).strip(), match.group(3), match.group(4)
        if apt:
            return f"г. {city}, ул. {street}, д. {house}, кв. {apt}"
        return f"г. {city}, ул. {street}, д. {house}"
    return None


def main():
    print("=== Task 1: Dates count and format d.m.y ===")
    dates, count = task1_dates()
    print(f"Found {count} dates")
    for d in dates:
        print(d)
    print()
    print("=== Task 2: Numbers followed by м ===")
    nums_m = task2_numbers_with_m()
    for val, pos in nums_m:
        print(f"Value: {val}, position: {pos}")
    print()
    print("=== Task 3: Phone number validation ===")
    phones = task3_phone_validation()
    for phone, valid in phones:
        status = "valid" if valid else "invalid"
        print(f"{phone} - {status}")
    print()
    print("=== Task 4: Words with uppercase letters ===")
    uppercase_count = task4_uppercase_words()
    print(f"Words with uppercase: {uppercase_count}")
    print()
    print("=== Task 5: Address format ===")
    addr = task5_address()
    if addr:
        print(addr)
    else:
        print("Address not found")


main()
