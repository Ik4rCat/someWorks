# Проверка на палиндром

## Чек-лист

| # | Проверка | Статус |
|---|----------|--------|
| 1 | Проверка корректного ввода (обычный палиндром) | + |
| 2 | Проверка игнорирования регистра | + |
| 3 | Проверка игнорирования пробелов и знаков препинания | + |
| 4 | Проверка пустой строки (граничное значение) | + |
| 5 | Проверка строки из одного символа (граничное значение) | + |
| 6 | Проверка некорректных данных (не палиндром) | + |
| 7 | Проверка исключений (не строковый тип) | + |

---

## Тест-кейсы

| № | Входные данные | Ожидаемый результат | Описание |
|---|----------------|---------------------|----------|
| 1 | `"abba"` | `True` | Обычный палиндром |
| 2 | `"hello"` | `False` | Не палиндром |
| 3 | `""` | `True` | Пустая строка |
| 4 | `"A"` | `True` | Один символ |
| 5 | `"A man a plan a canal Panama"` | `True` | Палиндром с пробелами и разным регистром |
| 6 | `"Was it a car or a cat I saw?"` | `True` | Палиндром со знаками препинания |
| 7 | `"race a car"` | `False` | Не палиндром с пробелами |
| 8 | `"No 'x' in Nixon"` | `True` | Палиндром с апострофами |
| 9 | `12321` | `TypeError` | Число вместо строки |
| 10 | `None` | `TypeError` | None вместо строки |

---

## Реализация:
```python
def is_palindrome(s: str) -> bool:
    cleaned = re.sub(r'[^a-zA-Zа-яА-ЯёЁ0-9]', '', s).lower()
    return cleaned == cleaned[::-1]
```

#Unit-test

```python
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

```

# Результат
```zsh
===================================== test session starts=====================================
platform linux -- Python 3.14.4, pytest-9.0.3, pluggy-1.6.0 -- /home/altemma/projects/SomeWorks/python/tests/300426/venv/bin/python
cachedir: .pytest_cache
rootdir: /home/altemma/projects/SomeWorks/python/tests/300426
collected 14 items                                                                                                                                                                  

test_program.py::test_is_palindrome_parametrized[abba-True] PASSED                          [  7%]
test_program.py::test_is_palindrome_parametrized[hello-False] PASSED                        [ 14%]
test_program.py::test_is_palindrome_parametrized[-True] PASSED                              [ 21%]
test_program.py::test_is_palindrome_parametrized[A-True] PASSED                             [ 28%]
test_program.py::test_is_palindrome_parametrized[A man a plan a canal Panama-True] PASSED   [ 35%]
test_program.py::test_is_palindrome_parametrized[Was it a car or a cat I saw?-True] PASSED  [ 42%]
test_program.py::test_is_palindrome_parametrized[race a car-False] PASSED                   [ 50%]
test_program.py::test_is_palindrome_parametrized[No 'x' in Nixon-True] PASSED               [ 57%]
test_program.py::test_is_palindrome_ignores_case PASSED                                     [ 64%]
test_program.py::test_is_palindrome_ignores_punctuation PASSED                              [ 71%]
test_program.py::test_is_palindrome_single_char PASSED                                      [ 78%]
test_program.py::test_is_palindrome_not_palindrome PASSED                                   [ 85%]
test_program.py::test_is_palindrome_raises_on_non_string PASSED                             [ 92%]
test_program.py::test_is_palindrome_raises_on_none PASSED                                   [100%]

===================================== 14 passed in 0.01s=====================================

```

