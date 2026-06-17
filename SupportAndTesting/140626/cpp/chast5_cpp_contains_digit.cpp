#include <gtest/gtest.h>
#include <string>
#include <cctype>

bool containsDigit(const std::string& s) {
    for (char c : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) return true;
    }
    return false;
}

TEST(ContainsDigitTest, EmptyString) {
    EXPECT_FALSE(containsDigit(""));
}

TEST(ContainsDigitTest, OnlyDigits) {
    EXPECT_TRUE(containsDigit("12345"));
}

TEST(ContainsDigitTest, OnlyLetters) {
    EXPECT_FALSE(containsDigit("abcdef"));
}

TEST(ContainsDigitTest, MixedString) {
    EXPECT_TRUE(containsDigit("hello3world"));
}

TEST(ContainsDigitTest, SpecialCharsOnly) {
    EXPECT_FALSE(containsDigit("!@#$%^"));
}

TEST(ContainsDigitTest, SpecialCharsWithDigit) {
    EXPECT_TRUE(containsDigit("!@#1$%"));
}

TEST(ContainsDigitTest, DigitAtStart) {
    EXPECT_TRUE(containsDigit("1abc"));
}

TEST(ContainsDigitTest, DigitAtEnd) {
    EXPECT_TRUE(containsDigit("abc9"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
