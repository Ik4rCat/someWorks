# Результаты: char_count_tests.py

```
pytest char_count_tests.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 11 items

char_count_tests.py::test_empty_string          PASSED [ 9%]
char_count_tests.py::test_repeated_char         PASSED [18%]
char_count_tests.py::test_all_unique            PASSED [27%]
char_count_tests.py::test_string_with_spaces    PASSED [36%]
char_count_tests.py::test_only_spaces           PASSED [45%]
char_count_tests.py::test_digits                PASSED [54%]
char_count_tests.py::test_special_chars         PASSED [63%]
char_count_tests.py::test_unicode_cyrillic      PASSED [72%]
char_count_tests.py::test_unicode_emoji         PASSED [81%]
char_count_tests.py::test_case_sensitive        PASSED [90%]
char_count_tests.py::test_mixed_string          PASSED [100%]

========================== 11 passed in 0.02s ==========================
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| test_empty_string | ✅ PASS | `""` | `{}` |
| test_repeated_char | ✅ PASS | `"aaa"` | `{'a': 3}` |
| test_all_unique | ✅ PASS | `"abc"` | `{'a':1, 'b':1, 'c':1}` |
| test_string_with_spaces | ✅ PASS | `"a b"` | `{'a':1, ' ':1, 'b':1}` |
| test_only_spaces | ✅ PASS | `"   "` | `{' ': 3}` |
| test_digits | ✅ PASS | `"112"` | `{'1':2, '2':1}` |
| test_special_chars | ✅ PASS | `"!@!"` | `{'!':2, '@':1}` |
| test_unicode_cyrillic | ✅ PASS | `"аба"` | `{'а':2, 'б':1}` |
| test_unicode_emoji | ✅ PASS | `"😀😀😁"` | `{'😀':2, '😁':1}` |
| test_case_sensitive | ✅ PASS | `"aAbB"` | `{'a':1,'A':1,'b':1,'B':1}` |
| test_mixed_string | ✅ PASS | `"a1!a1"` | `{'a':2,'1':2,'!':1}` |
