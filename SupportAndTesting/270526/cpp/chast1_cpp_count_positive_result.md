# Результаты: chast1_cpp_count_positive.cpp

```
./count_positive_tests

[==========] Running 7 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 7 tests from CountPositiveTest
[ RUN      ] CountPositiveTest.AllPositive
[       OK ] CountPositiveTest.AllPositive (0 ms)
[ RUN      ] CountPositiveTest.AllNegative
[       OK ] CountPositiveTest.AllNegative (0 ms)
[ RUN      ] CountPositiveTest.Mixed
[       OK ] CountPositiveTest.Mixed (0 ms)
[ RUN      ] CountPositiveTest.OnlyZeros
[       OK ] CountPositiveTest.OnlyZeros (0 ms)
[ RUN      ] CountPositiveTest.EmptyArray
[       OK ] CountPositiveTest.EmptyArray (0 ms)
[ RUN      ] CountPositiveTest.SinglePositive
[       OK ] CountPositiveTest.SinglePositive (0 ms)
[ RUN      ] CountPositiveTest.SingleNegative
[       OK ] CountPositiveTest.SingleNegative (0 ms)
[----------] 7 tests from CountPositiveTest (0 ms total)
[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 7 tests.
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| AllPositive | ✅ PASS | {1, 2, 3} | 3 |
| AllNegative | ✅ PASS | {-1, -2, -3} | 0 |
| Mixed | ✅ PASS | {-1, 0, 1, 2} | 2 |
| OnlyZeros | ✅ PASS | {0, 0, 0} | 0 (ноль не положительный) |
| EmptyArray | ✅ PASS | {} | 0 |
| SinglePositive | ✅ PASS | {42} | 1 |
| SingleNegative | ✅ PASS | {-7} | 0 |
