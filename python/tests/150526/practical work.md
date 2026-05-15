**Файлы:**
- `functions.py` — реализация функций
- `test_functions.py` — unit-тесты
- `results.md` — результаты запуска тестов

---

## Задание 3: Подсчёт слов

### Реализация

```python
def count_words(s: str) -> int:
    if not isinstance(s, str):
        raise TypeError("Input must be a string")
    return len(s.split())
```

### Чек-лист

| #   | Проверка                                  | Статус |
| --- | ----------------------------------------- | ------ |
| 1   | Строка с несколькими словами              | +      |
| 2   | Лишние пробелы между словами игнорируются | +      |
| 3   | Пустая строка — 0 слов                    | +      |
| 4   | Строка только из пробелов — 0 слов        | +      |
| 5   | Одно слово — 1                            | +      |
| 6   | Нечисловой тип вместо строки — TypeError  | +      |

### Тест-кейсы

| № | Входные данные | Ожидаемый результат | Описание |
|---|----------------|---------------------|----------|
| 1 | `"hello world"` | `2` | Два слова |
| 2 | `"  hello  world  "` | `2` | Лишние пробелы |
| 3 | `""` | `0` | Пустая строка |
| 4 | `"   "` | `0` | Только пробелы |
| 5 | `"hello"` | `1` | Одно слово |
| 6 | `123` | `TypeError` | Не строка |

### Unit-тесты

```python
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
```

### Скриншот запуска тестов

![[Pasted image 20260515132416.png]]

---

## Задание 4: Факториал

### Реализация

```python
def factorial(n: int) -> int:
    if isinstance(n, bool) or not isinstance(n, int):
        raise TypeError("Input must be an integer")
    if n < 0:
        raise ValueError("Factorial is not defined for negative numbers")
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result
```

### Чек-лист

| # | Проверка | Статус |
|---|----------|--------|
| 1 | Положительное число — корректный результат | + |
| 2 | 0! = 1 (граничное значение) | + |
| 3 | 1! = 1 (граничное значение) | + |
| 4 | Большое число (10) — корректный результат | + |
| 5 | Отрицательное число — ValueError | + |
| 6 | Нечисловой тип — TypeError | + |

### Тест-кейсы

| № | Входные данные | Ожидаемый результат | Описание |
|---|----------------|---------------------|----------|
| 1 | `5` | `120` | Обычный факториал |
| 2 | `0` | `1` | Граничное: 0! |
| 3 | `1` | `1` | Граничное: 1! |
| 4 | `10` | `3628800` | Большое число |
| 5 | `-1` | `ValueError` | Отрицательное число |
| 6 | `"5"` | `TypeError` | Строка вместо числа |

### Unit-тесты

```python
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
```

### Скриншот запуска тестов

![[Pasted image 20260515132338.png]]

---

## Задание 5: Проверка пароля

### Реализация

```python
def is_strong_password(password: str) -> bool:
    if not isinstance(password, str):
        raise TypeError("Password must be a string")
    return (
        len(password) >= 8
        and any(c.isdigit() for c in password)
        and any(c.isupper() for c in password)
    )
```

### Чек-лист

| # | Проверка | Статус |
|---|----------|--------|
| 1 | Валидный пароль (≥8 символов, цифра, заглавная) — True | + |
| 2 | Слишком короткий (< 8 символов) — False | + |
| 3 | Нет цифр — False | + |
| 4 | Нет заглавных букв — False | + |
| 5 | Ровно 8 символов — граничное значение | + |
| 6 | Нечисловой тип — TypeError | + |

### Тест-кейсы

| № | Входные данные | Ожидаемый результат | Описание |
|---|----------------|---------------------|----------|
| 1 | `"Test1234"` | `True` | Валидный пароль |
| 2 | `"test1234"` | `False` | Нет заглавной буквы |
| 3 | `"Test123"` | `False` | Слишком короткий (7 символов) |
| 4 | `"TESTTEST"` | `False` | Нет цифры |
| 5 | `"Test1234!"` | `True` | Со спецсимволом |
| 6 | `"T1aaaaaa"` | `True` | Ровно 8 символов (граничное) |
| 7 | `12345678` | `TypeError` | Не строка |

### Unit-тесты

```python
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
```

### Скриншот запуска тестов

![[Pasted image 20260515132304.png]]

---

## Задание 6: Проверка email

### Реализация

```python
def is_valid_email(email: str) -> bool:
    if not isinstance(email, str):
        raise TypeError("Email must be a string")
    if ' ' in email:
        return False
    parts = email.split('@')
    if len(parts) != 2:
        return False
    local, domain = parts
    if not local or not domain:
        return False
    dot_idx = domain.rfind('.')
    if dot_idx < 1 or dot_idx == len(domain) - 1:
        return False
    return True
```

### Чек-лист

| # | Проверка | Статус |
|---|----------|--------|
| 1 | Корректный email — True | + |
| 2 | Нет символа @ — False | + |
| 3 | Нет домена после @ — False | + |
| 4 | Пробел в адресе — False | + |
| 5 | Несколько символов @ — False | + |
| 6 | Нет точки в домене — False | + |
| 7 | Нечисловой тип — TypeError | + |

### Тест-кейсы

| № | Входные данные | Ожидаемый результат | Описание |
|---|----------------|---------------------|----------|
| 1 | `"test@mail.com"` | `True` | Корректный email |
| 2 | `"testmail.com"` | `False` | Нет символа @ |
| 3 | `"test@"` | `False` | Нет домена |
| 4 | `"te st@mail.com"` | `False` | Пробел в адресе |
| 5 | `"test@@mail.com"` | `False` | Два символа @ |
| 6 | `"test@mailcom"` | `False` | Нет точки в домене |
| 7 | `None` | `TypeError` | None вместо строки |

### Unit-тесты

```python
@pytest.mark.parametrize("email, expected", [
    ("test@mail.com",      True),
    ("testmail.com",       False),
    ("test@",              False),
    ("te st@mail.com",     False),
    ("test@@mail.com",     False),
    ("test@mailcom",       False),
    ("user@sub.domain.io", True),
    ("@mail.com",          False),
])
def test_is_valid_email_parametrized(email, expected):
    assert is_valid_email(email) == expected


def test_is_valid_email_raises_on_non_string():
    with pytest.raises(TypeError):
        is_valid_email(None)
```

### Скриншот запуска тестов

![[Pasted image 20260515132204.png]]

---

## Общий результат

### Скриншот полного запуска

![[Pasted image 20260515132016.png]]

| Показатель | Значение |
|---|---|
| Всего тестов | 33 |
| Passed | 33 |
| Failed | 0 |
