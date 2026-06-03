# Результаты: zadanie1_division_tests.py

```
pytest zadanie1_division_tests.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 10 items

zadanie1_division_tests.py::test_positive_integers     PASSED  [ 10%]
zadanie1_division_tests.py::test_positive_floats       PASSED  [ 20%]
zadanie1_division_tests.py::test_negative_dividend     PASSED  [ 30%]
zadanie1_division_tests.py::test_negative_divisor      PASSED  [ 40%]
zadanie1_division_tests.py::test_both_negative         PASSED  [ 50%]
zadanie1_division_tests.py::test_fractional_result     PASSED  [ 60%]
zadanie1_division_tests.py::test_zero_dividend         PASSED  [ 70%]
zadanie1_division_tests.py::test_division_by_zero      PASSED  [ 80%]
zadanie1_division_tests.py::test_division_by_zero_float PASSED [ 90%]
zadanie1_division_tests.py::test_division_by_zero_negative PASSED [100%]

========================== 10 passed in 0.03s ==========================
```

| Тест | Статус | Описание |
|------|--------|----------|
| test_positive_integers | ✅ PASS | 10/2 == 5.0 |
| test_positive_floats | ✅ PASS | 7.5/2.5 == 3.0 |
| test_negative_dividend | ✅ PASS | -10/2 == -5.0 |
| test_negative_divisor | ✅ PASS | 10/-2 == -5.0 |
| test_both_negative | ✅ PASS | -6/-3 == 2.0 |
| test_fractional_result | ✅ PASS | 1/3 ≈ 0.333 |
| test_zero_dividend | ✅ PASS | 0/5 == 0.0 |
| test_division_by_zero | ✅ PASS | raises ZeroDivisionError |
| test_division_by_zero_float | ✅ PASS | raises ZeroDivisionError |
| test_division_by_zero_negative | ✅ PASS | raises ZeroDivisionError |
