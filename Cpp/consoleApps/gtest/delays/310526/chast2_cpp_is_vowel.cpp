// Часть 2 — C++
// Функция isVowel() — определяет, является ли символ гласной буквой (англ.).
// Unit-тесты с Google Test.

#include <gtest/gtest.h>
#include <cctype>

bool isVowel(char c) {
    char lower = std::tolower(c);
    return lower == 'a' || lower == 'e' || lower == 'i' ||
           lower == 'o' || lower == 'u';
}

// Чек-лист:
// 1. Строчные гласные ('a','e','i','o','u')                +
// 2. Заглавные гласные ('A','E','I','O','U')               +
// 3. Согласные буквы → false                               +
// 4. Цифры → false                                         +
// 5. Спецсимволы → false                                   +

// Тест-кейсы:
// №  Входные данные  Ожидаемый  Описание
// 1  'a'             true       строчная гласная
// 2  'A'             true       заглавная гласная
// 3  'b'             false      согласная
// 4  '3'             false      цифра
// 5  '!'             false      спецсимвол
// 6  'u'             true       строчная гласная u
// 7  'Z'             false      заглавная согласная

TEST(IsVowelTest, LowercaseVowels) {
    EXPECT_TRUE(isVowel('a'));
    EXPECT_TRUE(isVowel('e'));
    EXPECT_TRUE(isVowel('i'));
    EXPECT_TRUE(isVowel('o'));
    EXPECT_TRUE(isVowel('u'));
}

TEST(IsVowelTest, UppercaseVowels) {
    EXPECT_TRUE(isVowel('A'));
    EXPECT_TRUE(isVowel('E'));
    EXPECT_TRUE(isVowel('U'));
}

TEST(IsVowelTest, Consonants) {
    EXPECT_FALSE(isVowel('b'));
    EXPECT_FALSE(isVowel('z'));
    EXPECT_FALSE(isVowel('Z'));
}

TEST(IsVowelTest, Digits) {
    EXPECT_FALSE(isVowel('3'));
    EXPECT_FALSE(isVowel('0'));
}

TEST(IsVowelTest, SpecialChars) {
    EXPECT_FALSE(isVowel('!'));
    EXPECT_FALSE(isVowel(' '));
    EXPECT_FALSE(isVowel('@'));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
