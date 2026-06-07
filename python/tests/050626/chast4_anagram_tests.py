# Часть 4 (050626) — Поддержка и тестирование
# Функция: is_anagram(s1, s2) — проверка анаграмм

# ============================================================
# Чек-лист
# ============================================================
# [x] Разные регистры букв → игнорировать регистр
# [x] Наличие пробелов → игнорировать пробелы
# [x] Спецсимволы → игнорировать
# [x] Одинаковые строки → True (анаграмма самой себя)
# [x] Пустые строки → True (две пустые — анаграммы)
# [x] Одна пустая, другая нет → False
# [x] Классическая анаграмма → True
# [x] Не анаграмма → False

# ============================================================
# Реализация
# ============================================================
def is_anagram(s1: str, s2: str) -> bool:
    clean = lambda s: sorted(c.lower() for c in s if c.isalpha())
    return clean(s1) == clean(s2)


# ============================================================
# Test cases (таблица)
# ============================================================
# | # | s1              | s2              | Ожидаемый | Описание             |
# |---|-----------------|-----------------|-----------|----------------------|
# | 1 | "listen"        | "silent"        | True      | Классическая         |
# | 2 | "Listen"        | "Silent"        | True      | Разный регистр       |
# | 3 | "a bc"          | "cab"           | True      | Пробелы              |
# | 4 | "a!b@c"         | "cba"           | True      | Спецсимволы          |
# | 5 | "hello"         | "hello"         | True      | Одинаковые строки    |
# | 6 | ""              | ""              | True      | Обе пустые           |
# | 7 | ""              | "a"             | False     | Одна пустая          |
# | 8 | "hello"         | "world"         | False     | Не анаграмма         |
# | 9 | "rat"           | "car"           | False     | Разные буквы         |
# |10 | "Astronomer"    | "Moon starer"   | True      | Пробелы + регистр    |

import pytest

def test_classic():
    assert is_anagram("listen", "silent") is True

def test_different_case():
    assert is_anagram("Listen", "Silent") is True

def test_spaces():
    assert is_anagram("a bc", "cab") is True

def test_special_chars():
    assert is_anagram("a!b@c", "cba") is True

def test_same_strings():
    assert is_anagram("hello", "hello") is True

def test_both_empty():
    assert is_anagram("", "") is True

def test_one_empty():
    assert is_anagram("", "a") is False

def test_not_anagram():
    assert is_anagram("hello", "world") is False

def test_different_letters():
    assert is_anagram("rat", "car") is False

def test_spaces_and_case():
    assert is_anagram("Astronomer", "Moon starer") is True
