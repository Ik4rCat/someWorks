// Часть Б — C++
// Функция containsDigit() — проверяет наличие цифры в строке.
// Unit-тесты с Google Test.

#include <gtest/gtest.h>
#include <string>
#include <cctype>

bool containsDigit(const std::string& s) {
    for (char c : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            return true;
        }
    }
    return false;
}

// Чек-лист:
// 1. Строка только из букв → false                               +
// 2. Строка только из цифр → true                                +
// 3. Смешанная строка (буквы + цифры) → true                     +
// 4. Пустая строка → false                                       +
// 5. Спецсимволы без цифр → false                                +
// 6. Спецсимволы с цифрой → true                                 +
// 7. Одна цифра в строке → true                                  +
// 8. Цифра в конце строки → true                                 +

// Тест-кейсы:
// №  Входные данные   Ожидаемый  Описание
// 1  "hello"          false      только буквы
// 2  "12345"          true       только цифры
// 3  "abc3def"        true       цифра в середине
// 4  ""               false      пустая строка
// 5  "!@#$%"          false      спецсимволы без цифр
// 6  "!2@"            true       спецсимволы с цифрой
// 7  "a"              false      один символ — буква
// 8  "text9"          true       цифра в конце

TEST(ContainsDigitTest, OnlyLetters) {
    EXPECT_FALSE(containsDigit("hello"));
}

TEST(ContainsDigitTest, OnlyDigits) {
    EXPECT_TRUE(containsDigit("12345"));
}

TEST(ContainsDigitTest, MixedDigitInMiddle) {
    EXPECT_TRUE(containsDigit("abc3def"));
}

TEST(ContainsDigitTest, EmptyString) {
    EXPECT_FALSE(containsDigit(""));
}

TEST(ContainsDigitTest, SpecialCharsNoDigit) {
    EXPECT_FALSE(containsDigit("!@#$%"));
}

TEST(ContainsDigitTest, SpecialCharsWithDigit) {
    EXPECT_TRUE(containsDigit("!2@"));
}

TEST(ContainsDigitTest, SingleLetter) {
    EXPECT_FALSE(containsDigit("a"));
}

TEST(ContainsDigitTest, DigitAtEnd) {
    EXPECT_TRUE(containsDigit("text9"));
}

TEST(ContainsDigitTest, DigitAtStart) {
    EXPECT_TRUE(containsDigit("1text"));
}

TEST(ContainsDigitTest, ZeroIsDigit) {
    EXPECT_TRUE(containsDigit("abc0"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
