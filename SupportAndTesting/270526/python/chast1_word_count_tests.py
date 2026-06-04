"""
Часть 1 — Практическая часть Python
Написать функцию подсчёта количества слов заданной длины в строке.
"""
import pytest


# ==============================
# РЕАЛИЗАЦИЯ
# ==============================

def count_words_of_length(text: str, length: int) -> int:
    """Считает количество слов заданной длины в строке."""
    if not text:
        return 0
    words = text.split()
    # убираем спецсимволы по краям слова перед подсчётом
    clean = [w.strip(".,!?;:\"'()-") for w in words]
    return sum(1 for w in clean if len(w) == length)


# ==============================
# ЧЕК-ЛИСТ
# ==============================
# 1. Пустая строка → 0                                      +
# 2. Несколько пробелов подряд → split() корректно работает  +
# 3. Слова разной длины — считаются только нужной длины      +
# 4. Наличие спецсимволов (точки, запятые) — очищаются       +
# 5. Строка из одного слова нужной длины → 1                 +
# 6. Все слова нужной длины → count == len(words)            +
# 7. Нет слов нужной длины → 0                              +


# ==============================
# ТЕСТ-КЕЙСЫ
# ==============================
# №  Входные данные                     length  Ожидаемый  Описание
# 1  "hello world"                      5       2          оба слова длиной 5
# 2  ""                                 3       0          пустая строка
# 3  "a bb ccc dddd"                    3       1          одно слово длиной 3
# 4  "hi  there"                        5       1          два пробела подряд
# 5  "hello, world!"                    5       2          спецсимволы по краям
# 6  "cat dog bird"                     4       1          только "bird" нет, "dog"=3
# 7  "one two six"                      3       3          все по 3 буквы


# ==============================
# UNIT-ТЕСТЫ
# ==============================

@pytest.mark.parametrize("text, length, expected", [
    ("hello world", 5, 2),
    ("", 3, 0),
    ("a bb ccc dddd", 3, 1),
    ("hi  there", 5, 1),
    ("hello, world!", 5, 2),
    ("one two six", 3, 3),
    ("cat dog bird fish", 4, 2),
])
def test_count_words_parametrized(text, length, expected):
    assert count_words_of_length(text, length) == expected


def test_empty_string():
    assert count_words_of_length("", 5) == 0


def test_multiple_spaces():
    assert count_words_of_length("hello   world", 5) == 2


def test_special_chars():
    assert count_words_of_length("hello, world!", 5) == 2


def test_no_match():
    assert count_words_of_length("a bb ccc", 10) == 0


def test_single_word_match():
    assert count_words_of_length("python", 6) == 1
