import pytest
from functions import (
    count_words,
    factorial,
    is_strong_password,
    is_valid_email,
)


# ══════════════════════════════════════════════════════════════
# Задание 3: Подсчёт слов — count_words(s)
# ══════════════════════════════════════════════════════════════
#
# Чек-лист:
# 1. Строка с несколькими словами                                       +
# 2. Лишние пробелы между словами игнорируются                         +
# 3. Пустая строка — 0 слов                                            +
# 4. Строка только из пробелов — 0 слов                                +
# 5. Одно слово — 1                                                     +
# 6. Нечисловой тип вместо строки — TypeError                          +
#
# Тест-кейсы:
# ┌───┬─────────────────────┬────────────┬──────────────────────────────┐
# │ № │ Входные данные      │ Ожидаемый  │ Описание                     │
# ├───┼─────────────────────┼────────────┼──────────────────────────────┤
# │ 1 │ "hello world"       │ 2          │ Два слова                    │
# │ 2 │ "  hello  world  "  │ 2          │ Лишние пробелы               │
# │ 3 │ ""                  │ 0          │ Пустая строка                │
# │ 4 │ "   "               │ 0          │ Только пробелы               │
# │ 5 │ "hello"             │ 1          │ Одно слово                   │
# │ 6 │ 123                 │ TypeError  │ Не строка                    │
# └───┴─────────────────────┴────────────┴──────────────────────────────┘

@pytest.mark.parametrize("s, expected", [
    ("hello world",      2),
    ("  hello  world  ", 2),
    ("",                 0),
    ("   ",              0),
    ("hello",            1),
    ("one two three",    3),
])
def test_count_words_parametrized(s, expected):
    assert count_words(s) == expected


def test_count_words_raises_on_non_string():
    with pytest.raises(TypeError):
        count_words(123)


# ══════════════════════════════════════════════════════════════
# Задание 4: Факториал — factorial(n)
# ══════════════════════════════════════════════════════════════
#
# Чек-лист:
# 1. Положительное число — корректный результат                        +
# 2. 0! = 1 (граничное значение)                                       +
# 3. 1! = 1 (граничное значение)                                       +
# 4. Большое число (10) — корректный результат                         +
# 5. Отрицательное число — ValueError                                  +
# 6. Нечисловой тип — TypeError                                        +
#
# Тест-кейсы:
# ┌───┬────────────────┬───────────────┬──────────────────────────────┐
# │ № │ Входные данные │ Ожидаемый     │ Описание                     │
# ├───┼────────────────┼───────────────┼──────────────────────────────┤
# │ 1 │ 5              │ 120           │ Обычный факториал            │
# │ 2 │ 0              │ 1             │ Граничное: 0!                │
# │ 3 │ 1              │ 1             │ Граничное: 1!                │
# │ 4 │ 10             │ 3628800       │ Большое число                │
# │ 5 │ -1             │ ValueError    │ Отрицательное число          │
# │ 6 │ "5"            │ TypeError     │ Строка вместо числа          │
# └───┴────────────────┴───────────────┴──────────────────────────────┘

@pytest.mark.parametrize("n, expected", [
    (0,  1),
    (1,  1),
    (5,  120),
    (10, 3628800),
    (7,  5040),
])
def test_factorial_parametrized(n, expected):
    assert factorial(n) == expected


def test_factorial_raises_on_negative():
    with pytest.raises(ValueError):
        factorial(-1)


def test_factorial_raises_on_non_integer():
    with pytest.raises(TypeError):
        factorial("5")


def test_factorial_raises_on_float():
    with pytest.raises(TypeError):
        factorial(5.0)


# ══════════════════════════════════════════════════════════════
# Задание 5: Проверка пароля — is_strong_password(password)
# ══════════════════════════════════════════════════════════════
#
# Чек-лист:
# 1. Валидный пароль (≥8 символов, цифра, заглавная) — True            +
# 2. Слишком короткий (< 8 символов) — False                           +
# 3. Нет цифр — False                                                   +
# 4. Нет заглавных букв — False                                         +
# 5. Ровно 8 символов — граничное значение                             +
# 6. Нечисловой тип — TypeError                                        +
#
# Тест-кейсы:
# ┌───┬──────────────────┬────────────┬──────────────────────────────────┐
# │ № │ Входные данные   │ Ожидаемый  │ Описание                         │
# ├───┼──────────────────┼────────────┼──────────────────────────────────┤
# │ 1 │ "Test1234"       │ True       │ Валидный пароль                  │
# │ 2 │ "test1234"       │ False      │ Нет заглавной буквы              │
# │ 3 │ "Test123"        │ False      │ Слишком короткий (7 символов)    │
# │ 4 │ "TESTTEST"       │ False      │ Нет цифры                        │
# │ 5 │ "Test1234!"      │ True       │ Со спецсимволом                  │
# │ 6 │ "T1aaaaaa"       │ True       │ Ровно 8 символов (граничное)     │
# │ 7 │ 12345678         │ TypeError  │ Не строка                        │
# └───┴──────────────────┴────────────┴──────────────────────────────────┘

@pytest.mark.parametrize("password, expected", [
    ("Test1234",   True),
    ("test1234",   False),
    ("Test123",    False),
    ("TESTTEST",   False),
    ("Test1234!",  True),
    ("T1aaaaaa",   True),
    ("A1aaaaaa",   True),
    ("a1aaaaaa",   False),
])
def test_is_strong_password_parametrized(password, expected):
    assert is_strong_password(password) == expected


def test_is_strong_password_raises_on_non_string():
    with pytest.raises(TypeError):
        is_strong_password(12345678)


# ══════════════════════════════════════════════════════════════
# Задание 6: Проверка email — is_valid_email(email)
# ══════════════════════════════════════════════════════════════
#
# Чек-лист:
# 1. Корректный email — True                                            +
# 2. Нет символа @ — False                                             +
# 3. Нет домена после @ — False                                        +
# 4. Пробел в адресе — False                                           +
# 5. Несколько символов @ — False                                      +
# 6. Нет точки в домене — False                                        +
# 7. Нечисловой тип — TypeError                                        +
#
# Тест-кейсы:
# ┌───┬──────────────────────┬────────────┬──────────────────────────────┐
# │ № │ Входные данные       │ Ожидаемый  │ Описание                     │
# ├───┼──────────────────────┼────────────┼──────────────────────────────┤
# │ 1 │ "test@mail.com"      │ True       │ Корректный email             │
# │ 2 │ "testmail.com"       │ False      │ Нет символа @                │
# │ 3 │ "test@"              │ False      │ Нет домена                   │
# │ 4 │ "te st@mail.com"     │ False      │ Пробел в адресе              │
# │ 5 │ "test@@mail.com"     │ False      │ Два символа @                │
# │ 6 │ "test@mailcom"       │ False      │ Нет точки в домене           │
# │ 7 │ None                 │ TypeError  │ None вместо строки           │
# └───┴──────────────────────┴────────────┴──────────────────────────────┘

@pytest.mark.parametrize("email, expected", [
    ("test@mail.com",     True),
    ("testmail.com",      False),
    ("test@",             False),
    ("te st@mail.com",    False),
    ("test@@mail.com",    False),
    ("test@mailcom",      False),
    ("user@sub.domain.io", True),
    ("@mail.com",         False),
])
def test_is_valid_email_parametrized(email, expected):
    assert is_valid_email(email) == expected


def test_is_valid_email_raises_on_non_string():
    with pytest.raises(TypeError):
        is_valid_email(None)
