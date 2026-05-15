# Результаты тестов — 150526

## Задания
- Задание 3: Подсчёт слов (`count_words`)
- Задание 4: Факториал (`factorial`)
- Задание 5: Проверка пароля (`is_strong_password`)
- Задание 6: Проверка email (`is_valid_email`)

---

## Запуск

```
pytest test_functions.py -v
```

---

## Результат

```
============================= test session starts ==============================
platform linux -- Python 3.14.4, pytest-9.0.3, pluggy-1.6.0 -- /usr/bin/python
cachedir: .pytest_cache
rootdir: /home/altemma/projects/SomeWorks/python/tests/150526
collected 33 items

test_functions.py::test_count_words_parametrized[hello world-2] PASSED   [  3%]
test_functions.py::test_count_words_parametrized[  hello  world  -2] PASSED [  6%]
test_functions.py::test_count_words_parametrized[-0] PASSED              [  9%]
test_functions.py::test_count_words_parametrized[   -0] PASSED           [ 12%]
test_functions.py::test_count_words_parametrized[hello-1] PASSED         [ 15%]
test_functions.py::test_count_words_parametrized[one two three-3] PASSED [ 18%]
test_functions.py::test_count_words_raises_on_non_string PASSED          [ 21%]
test_functions.py::test_factorial_parametrized[0-1] PASSED               [ 24%]
test_functions.py::test_factorial_parametrized[1-1] PASSED               [ 27%]
test_functions.py::test_factorial_parametrized[5-120] PASSED             [ 30%]
test_functions.py::test_factorial_parametrized[10-3628800] PASSED        [ 33%]
test_functions.py::test_factorial_parametrized[7-5040] PASSED            [ 36%]
test_functions.py::test_factorial_raises_on_negative PASSED              [ 39%]
test_functions.py::test_factorial_raises_on_non_integer PASSED           [ 42%]
test_functions.py::test_factorial_raises_on_float PASSED                 [ 45%]
test_functions.py::test_is_strong_password_parametrized[Test1234-True] PASSED [ 48%]
test_functions.py::test_is_strong_password_parametrized[test1234-False] PASSED [ 51%]
test_functions.py::test_is_strong_password_parametrized[Test123-False] PASSED [ 54%]
test_functions.py::test_is_strong_password_parametrized[TESTTEST-False] PASSED [ 57%]
test_functions.py::test_is_strong_password_parametrized[Test1234!-True] PASSED [ 60%]
test_functions.py::test_is_strong_password_parametrized[T1aaaaaa-True] PASSED [ 63%]
test_functions.py::test_is_strong_password_parametrized[A1aaaaaa-True] PASSED [ 66%]
test_functions.py::test_is_strong_password_parametrized[a1aaaaaa-False] PASSED [ 69%]
test_functions.py::test_is_strong_password_raises_on_non_string PASSED   [ 72%]
test_functions.py::test_is_valid_email_parametrized[test@mail.com-True] PASSED [ 75%]
test_functions.py::test_is_valid_email_parametrized[testmail.com-False] PASSED [ 78%]
test_functions.py::test_is_valid_email_parametrized[test@-False] PASSED  [ 81%]
test_functions.py::test_is_valid_email_parametrized[te st@mail.com-False] PASSED [ 84%]
test_functions.py::test_is_valid_email_parametrized[test@@mail.com-False] PASSED [ 87%]
test_functions.py::test_is_valid_email_parametrized[test@mailcom-False] PASSED [ 90%]
test_functions.py::test_is_valid_email_parametrized[user@sub.domain.io-True] PASSED [ 93%]
test_functions.py::test_is_valid_email_parametrized[@mail.com-False] PASSED [ 96%]
test_functions.py::test_is_valid_email_raises_on_non_string PASSED       [100%]

============================== 33 passed in 0.03s ==============================
```

---

## Итог

| Показатель | Значение |
|---|---|
| Всего тестов | 33 |
| Passed | 33 |
| Failed | 0 |
| Время | 0.03s |
