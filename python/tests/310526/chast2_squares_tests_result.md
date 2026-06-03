# Результаты: chast2_squares_tests.py

```
pytest chast2_squares_tests.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 11 items

chast2_squares_tests.py::test_generate_squares_parametrized[5-expected0]    PASSED [ 9%]
chast2_squares_tests.py::test_generate_squares_parametrized[0-expected1]    PASSED [18%]
chast2_squares_tests.py::test_generate_squares_parametrized[1-expected2]    PASSED [27%]
chast2_squares_tests.py::test_generate_squares_parametrized[3-expected3]    PASSED [36%]
chast2_squares_tests.py::test_generate_squares_parametrized[10-expected4]   PASSED [45%]
chast2_squares_tests.py::test_n_zero_returns_empty                           PASSED [54%]
chast2_squares_tests.py::test_negative_raises                                PASSED [63%]
chast2_squares_tests.py::test_return_type_is_list                            PASSED [72%]
chast2_squares_tests.py::test_large_n                                        PASSED [81%]
chast2_squares_tests.py::test_n_one                                          PASSED [90%]

========================== 10 passed in 0.03s ==========================
```

| Тест | Статус | N | Ожидаемый выход |
|------|--------|---|-----------------|
| parametrized N=5 | ✅ PASS | 5 | [1, 4, 9, 16, 25] |
| parametrized N=0 | ✅ PASS | 0 | [] |
| parametrized N=1 | ✅ PASS | 1 | [1] |
| parametrized N=3 | ✅ PASS | 3 | [1, 4, 9] |
| parametrized N=10 | ✅ PASS | 10 | [1, 4, 9, ..., 100] |
| test_n_zero_returns_empty | ✅ PASS | 0 | [] |
| test_negative_raises | ✅ PASS | -1 | ValueError |
| test_return_type_is_list | ✅ PASS | 5 | isinstance(result, list) |
| test_large_n | ✅ PASS | 100 | len=100, last=10000 |
| test_n_one | ✅ PASS | 1 | [1] |
