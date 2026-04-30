import pytest
from program import is_palindrome


# Чек-лист:
# 1. Проверка корректного ввода — обычный палиндром                  +
# 2. Проверка игнорирования регистра                                 +
# 3. Проверка игнорирования пробелов и знаков препинания             +
# 4. Проверка пустой строки (граничное значение)                     +
# 5. Проверка строки из одного символа (граничное значение)          +
# 6. Проверка некорректного типа данных (невалидные данные)          +
# 7. Проверка строки, не являющейся палиндромом (негативный сценарий)+


@pytest.mark.parametrize("s, expected", [
    ("abba", True),
    ("hello", False),
    ("", True),
    ("A", True),
    ("A man a plan a canal Panama", True),
    ("Was it a car or a cat I saw?", True),
    ("race a car", False),
    ("No 'x' in Nixon", True),
])
def test_is_palindrome_parametrized(s, expected):
    assert is_palindrome(s) == expected


def test_is_palindrome_ignores_case():
    assert is_palindrome("Madam") is True


def test_is_palindrome_ignores_punctuation():
    assert is_palindrome("A man, a plan, a canal: Panama") is True


def test_is_palindrome_single_char():
    assert is_palindrome("Z") is True


def test_is_palindrome_not_palindrome():
    assert is_palindrome("Python") is False


def test_is_palindrome_raises_on_non_string():
    with pytest.raises((TypeError, AttributeError)):
        is_palindrome(12321)


def test_is_palindrome_raises_on_none():
    with pytest.raises((TypeError, AttributeError)):
        is_palindrome(None)
