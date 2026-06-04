# Результаты: chast1_word_count_tests.py

```
pytest chast1_word_count_tests.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 12 items

chast1_word_count_tests.py::test_count_words_parametrized[hello world-5-2]        PASSED [  8%]
chast1_word_count_tests.py::test_count_words_parametrized[-3-0]                   PASSED [ 16%]
chast1_word_count_tests.py::test_count_words_parametrized[a bb ccc dddd-3-1]      PASSED [ 25%]
chast1_word_count_tests.py::test_count_words_parametrized[hi  there-5-1]          PASSED [ 33%]
chast1_word_count_tests.py::test_count_words_parametrized[hello, world!-5-2]      PASSED [ 41%]
chast1_word_count_tests.py::test_count_words_parametrized[one two six-3-3]        PASSED [ 50%]
chast1_word_count_tests.py::test_count_words_parametrized[cat dog bird fish-4-2]  PASSED [ 58%]
chast1_word_count_tests.py::test_empty_string                                      PASSED [ 66%]
chast1_word_count_tests.py::test_multiple_spaces                                   PASSED [ 75%]
chast1_word_count_tests.py::test_special_chars                                     PASSED [ 83%]
chast1_word_count_tests.py::test_no_match                                          PASSED [ 91%]
chast1_word_count_tests.py::test_single_word_match                                 PASSED [100%]

========================== 12 passed in 0.03s ==========================
```

| Тест | Статус | Вход | length | Ожидаемый выход |
|------|--------|------|--------|-----------------|
| "hello world" | ✅ PASS | два слова | 5 | 2 |
| "" (пустая) | ✅ PASS | пустая строка | 3 | 0 |
| "a bb ccc dddd" | ✅ PASS | разной длины | 3 | 1 |
| "hi  there" | ✅ PASS | двойной пробел | 5 | 1 |
| "hello, world!" | ✅ PASS | знаки препинания | 5 | 2 |
| "one two six" | ✅ PASS | все по 3 | 3 | 3 |
| "cat dog bird fish" | ✅ PASS | смешанные | 4 | 2 |
| test_empty_string | ✅ PASS | "" | 5 | 0 |
| test_multiple_spaces | ✅ PASS | несколько пробелов | 5 | 2 |
| test_special_chars | ✅ PASS | запятые/точки | 5 | 2 |
| test_no_match | ✅ PASS | нет слов длиной 10 | 10 | 0 |
| test_single_word_match | ✅ PASS | "python" | 6 | 1 |
