# Результаты: chast2_cpp_is_vowel.cpp

```
./is_vowel_tests

[==========] Running 5 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 5 tests from IsVowelTest
[ RUN      ] IsVowelTest.LowercaseVowels
[       OK ] IsVowelTest.LowercaseVowels (0 ms)
[ RUN      ] IsVowelTest.UppercaseVowels
[       OK ] IsVowelTest.UppercaseVowels (0 ms)
[ RUN      ] IsVowelTest.Consonants
[       OK ] IsVowelTest.Consonants (0 ms)
[ RUN      ] IsVowelTest.Digits
[       OK ] IsVowelTest.Digits (0 ms)
[ RUN      ] IsVowelTest.SpecialChars
[       OK ] IsVowelTest.SpecialChars (0 ms)
[----------] 5 tests from IsVowelTest (0 ms total)
[----------] Global test environment tear-down
[==========] 5 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 5 tests.
```

| Тест | Статус | Вход | Ожидаемый выход |
|------|--------|------|-----------------|
| LowercaseVowels | ✅ PASS | 'a','e','i','o','u' | true для всех |
| UppercaseVowels | ✅ PASS | 'A','E','U' | true для всех |
| Consonants | ✅ PASS | 'b','z','Z' | false для всех |
| Digits | ✅ PASS | '3','0' | false для всех |
| SpecialChars | ✅ PASS | '!',' ','@' | false для всех |
