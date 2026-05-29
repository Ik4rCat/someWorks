# Лабораторная работа I — Обработка текста

## Блок 1: Импорты и текст

Подключение `re`, исходный текст и словарь названий месяцев → номер.

```python
import re

TEXT = """Дата: 14 января 2026 года.
..."""

MONTHS = {
    'января': 1, 'февраля': 2, 'марта': 3, 'апреля': 4, 'мая': 5, 'июня': 6,
    'июля': 7, 'августа': 8, 'сентября': 9, 'октября': 10, 'ноября': 11, 'декабря': 12
}
```

## Блок 2: Задача 1 — Даты

Ищет даты вида «14 января 2026 года» и переводит их в формат д.м.г.

```python
def task1_dates():
    pattern = r'(\d{1,2})\s+(января|февраля|...|декабря)\s+(\d{4})\s+года'
    matches = re.findall(pattern, TEXT)
    result = []
    for day, month_name, year in matches:
        month = MONTHS.get(month_name, 0)
        result.append(f"{day}.{month}.{year}")
    return result, len(result)
```

## Блок 3: Задача 2 — Числа перед «м»

Ищет числа, после которых идёт «м» (например 85 м², 2,8 м), возвращает значение и позицию.

```python
def task2_numbers_with_m():
    pattern = r'\d+(?:[.,]\d+)?\s*[‑\-]?\s*м'
    matches = re.finditer(pattern, TEXT)
    result = []
    for m in matches:
        result.append((m.group(), m.start()))
    return result
```

## Блок 4: Задача 3 — Проверка телефонов

Ищет строки, похожие на телефоны, и проверяет формат +7 и 11 цифр.

```python
def task3_phone_validation():
    phones = re.findall(r'\+\d[\s\d\-‑()]*\d', TEXT)
    result = []
    for phone in phones:
        clean = re.sub(r'\D', '', phone)
        is_valid = len(clean) == 11 and clean.startswith('79')
        result.append((phone.strip(), is_valid))
    return result
```

## Блок 5: Задача 4 — Слова с заглавной

Считает слова, в которых есть хотя бы одна заглавная буква.

```python
def task4_uppercase_words():
    words = re.findall(r'[а-яА-Яa-zA-ZёЁ]+', TEXT)
    count = sum(1 for w in words if any(c.isupper() for c in w))
    return count
```

## Блок 6: Задача 5 — Формат адреса

Ищет строку «Адрес:» и оформляет её как г. Город, ул. Улица, д. номер, кв. квартира (кв. только если есть).

```python
def task5_address():
    pattern = r'Адрес:\s*([^,]+),\s*([^,]+),\s*(\d+)(?:,\s*(\d+))?\.'
    match = re.search(pattern, TEXT)
    if match:
        city, street, house, apt = match.group(1).strip(), match.group(2).strip(), match.group(3), match.group(4)
        if apt:
            return f"г. {city}, ул. {street}, д. {house}, кв. {apt}"
        return f"г. {city}, ул. {street}, д. {house}"
    return None
```

## Блок 7: Main

Вызывает все задачи и выводит результаты.

```python
def main():
    print("=== Task 1: Dates count and format d.m.y ===")
    dates, count = task1_dates()
    # ... prints for all tasks

if __name__ == "__main__":
    main()
```

## Вывод по работе

В работе использованы регулярные выражения для разбора текста: поиск дат, чисел с единицами измерения, телефонов, слов с заглавными буквами и адресов. Регулярки позволяют задавать формат данных и извлекать или проверять их без ручного перебора символов. Усвоены приёмы работы с модулем `re` (findall, finditer, search, группы), преобразование текстовых дат в формат д.м.г и приведение адреса к единому виду.
