# Результаты: zadacha1_discount_tests.py

```
pytest zadacha1_discount_tests.py -v

========================= test session starts ==========================
platform linux -- Python 3.x, pytest-x.x.x
collected 9 items

zadacha1_discount_tests.py::test_calculate_discount_valid[100-20-80.0]   PASSED [ 11%]
zadacha1_discount_tests.py::test_calculate_discount_valid[200-50-100.0]  PASSED [ 22%]
zadacha1_discount_tests.py::test_calculate_discount_valid[150-0-150.0]   PASSED [ 33%]
zadacha1_discount_tests.py::test_calculate_discount_valid[99-100-0.0]    PASSED [ 44%]
zadacha1_discount_tests.py::test_calculate_discount_valid[60-10-54.0]    PASSED [ 55%]
zadacha1_discount_tests.py::test_calculate_discount_valid[1000-33-670.0] PASSED [ 66%]
zadacha1_discount_tests.py::test_negative_price_raises                   PASSED [ 77%]
zadacha1_discount_tests.py::test_discount_above_100_raises               PASSED [ 88%]
zadacha1_discount_tests.py::test_discount_below_0_raises                 PASSED [100%]

========================== 9 passed in 0.04s ==========================
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| valid[100-20-80.0] | ✅ PASS | price=100, disc=20 | 80.0 |
| valid[200-50-100.0] | ✅ PASS | price=200, disc=50 | 100.0 |
| valid[150-0-150.0] | ✅ PASS | скидка 0% | цена не меняется |
| valid[99-100-0.0] | ✅ PASS | скидка 100% | цена = 0 |
| valid[60-10-54.0] | ✅ PASS | price=60, disc=10 | 54.0 |
| valid[1000-33-670.0] | ✅ PASS | price=1000, disc=33 | 670.0 |
| test_negative_price_raises | ✅ PASS | price=-50 | ValueError |
| test_discount_above_100_raises | ✅ PASS | disc=110 | ValueError |
| test_discount_below_0_raises | ✅ PASS | disc=-5 | ValueError |
