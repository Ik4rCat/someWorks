# Результаты: contains_digit_test.cpp

```
./contains_digit_test

[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from ContainsDigitTest
[ RUN      ] ContainsDigitTest.OnlyLetters
[       OK ] ContainsDigitTest.OnlyLetters (0 ms)
[ RUN      ] ContainsDigitTest.OnlyDigits
[       OK ] ContainsDigitTest.OnlyDigits (0 ms)
[ RUN      ] ContainsDigitTest.MixedDigitInMiddle
[       OK ] ContainsDigitTest.MixedDigitInMiddle (0 ms)
[ RUN      ] ContainsDigitTest.EmptyString
[       OK ] ContainsDigitTest.EmptyString (0 ms)
[ RUN      ] ContainsDigitTest.SpecialCharsNoDigit
[       OK ] ContainsDigitTest.SpecialCharsNoDigit (0 ms)
[ RUN      ] ContainsDigitTest.SpecialCharsWithDigit
[       OK ] ContainsDigitTest.SpecialCharsWithDigit (0 ms)
[ RUN      ] ContainsDigitTest.SingleLetter
[       OK ] ContainsDigitTest.SingleLetter (0 ms)
[ RUN      ] ContainsDigitTest.DigitAtEnd
[       OK ] ContainsDigitTest.DigitAtEnd (0 ms)
[ RUN      ] ContainsDigitTest.DigitAtStart
[       OK ] ContainsDigitTest.DigitAtStart (0 ms)
[ RUN      ] ContainsDigitTest.ZeroIsDigit
[       OK ] ContainsDigitTest.ZeroIsDigit (0 ms)
[----------] 10 tests from ContainsDigitTest (0 ms total)
[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 10 tests.
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| OnlyLetters | ✅ PASS | `"hello"` | `false` |
| OnlyDigits | ✅ PASS | `"12345"` | `true` |
| MixedDigitInMiddle | ✅ PASS | `"abc3def"` | `true` |
| EmptyString | ✅ PASS | `""` | `false` |
| SpecialCharsNoDigit | ✅ PASS | `"!@#$%"` | `false` |
| SpecialCharsWithDigit | ✅ PASS | `"!2@"` | `true` |
| SingleLetter | ✅ PASS | `"a"` | `false` |
| DigitAtEnd | ✅ PASS | `"text9"` | `true` |
| DigitAtStart | ✅ PASS | `"1text"` | `true` |
| ZeroIsDigit | ✅ PASS | `"abc0"` | `true` |
