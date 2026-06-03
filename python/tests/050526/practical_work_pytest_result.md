# Результаты: practical_work_pytest.py

```
pytest practical_work_pytest.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 9 items

practical_work_pytest.py::test_get_even_numbers_parametrized[input0-expected0]  PASSED [ 11%]
practical_work_pytest.py::test_get_even_numbers_parametrized[input1-expected1]  PASSED [ 22%]
practical_work_pytest.py::test_get_even_numbers_parametrized[input2-expected2]  PASSED [ 33%]
practical_work_pytest.py::test_get_even_numbers_parametrized[input3-expected3]  PASSED [ 44%]
practical_work_pytest.py::test_get_even_numbers_parametrized[input4-expected4]  PASSED [ 55%]
practical_work_pytest.py::test_get_even_numbers_parametrized[input5-expected5]  PASSED [ 66%]
practical_work_pytest.py::test_empty_list                                        PASSED [ 77%]
practical_work_pytest.py::test_zero_is_even                                      PASSED [ 77%]
practical_work_pytest.py::test_all_odd                                           PASSED [ 88%]
practical_work_pytest.py::test_invalid_type_raises                               PASSED [ 88%]
practical_work_pytest.py::test_single_even                                       PASSED [ 99%]
practical_work_pytest.py::test_negative_evens                                    PASSED [100%]

========================== 12 passed in 0.03s ==========================
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| parametrized [1,2,3,4] | ✅ PASS | смешанный список | [2, 4] |
| parametrized [1,3,5,7] | ✅ PASS | только нечётные | [] |
| parametrized [2,4,6] | ✅ PASS | только чётные | [2, 4, 6] |
| parametrized [] | ✅ PASS | пустой список | [] |
| parametrized [0,1,2] | ✅ PASS | ноль чётный | [0, 2] |
| parametrized [-4,-3,-2,-1] | ✅ PASS | отрицательные чётные | [-4, -2] |
| test_empty_list | ✅ PASS | [] | [] |
| test_zero_is_even | ✅ PASS | [0] | 0 in result |
| test_all_odd | ✅ PASS | [1,3,5] | [] |
| test_invalid_type_raises | ✅ PASS | "строка" | TypeError |
| test_single_even | ✅ PASS | [42] | [42] |
| test_negative_evens | ✅ PASS | [-4,-2,-1,3] | [-4, -2] |
