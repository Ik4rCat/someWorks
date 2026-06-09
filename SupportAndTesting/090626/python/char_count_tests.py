# Часть Б — Python
# Функция подсчёта количества повторений символов в строке.
# Unit-тесты с pytest.

from collections import Counter


def char_count(s: str) -> dict:
    """Возвращает словарь {символ: количество вхождений} для строки s."""
    return dict(Counter(s))


# Чек-лист:
# 1. Пустая строка → пустой словарь                               +
# 2. Строка из одного символа                                      +
# 3. Строка с повторяющимися буквами                               +
# 4. Строка с пробелами (пробел — тоже символ)                     +
# 5. Строка из цифр                                                +
# 6. Строка со спецсимволами (!, @, #, ...)                        +
# 7. Строка с Unicode-символами (кириллица, эмодзи)                +
# 8. Смешанная строка (буквы + цифры + спецсимволы)                +
# 9. Регистр учитывается ('a' ≠ 'A')                               +

# Тест-кейсы:
# №  Входные данные     Ожидаемый результат                Описание
# 1  ""                 {}                                 пустая строка
# 2  "aaa"              {'a': 3}                           одна буква трижды
# 3  "abc"              {'a':1,'b':1,'c':1}                все разные
# 4  "a b"              {'a':1,' ':1,'b':1}                строка с пробелом
# 5  "123"              {'1':1,'2':1,'3':1}                только цифры
# 6  "!@#"              {'!':1,'@':1,'#':1}                спецсимволы
# 7  "привет"           {'п':1,'р':1,'и':1,'в':1,'е':1,'т':1}  кириллица
# 8  "😀😀"             {'😀': 2}                          эмодзи
# 9  "aAbB"             {'a':1,'A':1,'b':1,'B':1}          регистрозависимость

import pytest


def test_empty_string():
    """Пустая строка → пустой словарь."""
    assert char_count("") == {}


def test_repeated_char():
    """Один символ повторяется несколько раз."""
    assert char_count("aaa") == {'a': 3}


def test_all_unique():
    """Все символы уникальные."""
    assert char_count("abc") == {'a': 1, 'b': 1, 'c': 1}


def test_string_with_spaces():
    """Пробел тоже считается символом."""
    result = char_count("a b")
    assert result[' '] == 1
    assert result['a'] == 1
    assert result['b'] == 1


def test_only_spaces():
    """Строка только из пробелов."""
    assert char_count("   ") == {' ': 3}


def test_digits():
    """Строка из цифр."""
    assert char_count("112") == {'1': 2, '2': 1}


def test_special_chars():
    """Спецсимволы обрабатываются корректно."""
    result = char_count("!@!")
    assert result['!'] == 2
    assert result['@'] == 1


def test_unicode_cyrillic():
    """Unicode — кириллица."""
    result = char_count("аба")
    assert result['а'] == 2
    assert result['б'] == 1


def test_unicode_emoji():
    """Unicode — эмодзи."""
    assert char_count("😀😀😁") == {'😀': 2, '😁': 1}


def test_case_sensitive():
    """Регистр учитывается: 'a' и 'A' — разные символы."""
    result = char_count("aAbB")
    assert result['a'] == 1
    assert result['A'] == 1
    assert result['b'] == 1
    assert result['B'] == 1


def test_mixed_string():
    """Смешанная строка: буквы + цифры + спецсимволы."""
    result = char_count("a1!a1")
    assert result['a'] == 2
    assert result['1'] == 2
    assert result['!'] == 1


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
