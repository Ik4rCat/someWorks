#include <gtest/gtest.h>
#include <stdexcept>

#include "../library.h"

// Равно
TEST(MyTest, Equal) {
    EXPECT_EQ(library(3, 4), 12);
}

// Не равно
TEST(MyTest, NotEqual) {
    EXPECT_NE(library(3, 4), 0);
}

// Истина
TEST(MyTest, True) {
    EXPECT_TRUE(library(2, 5) > 0);
}

// Ложь
TEST(MyTest, False) {
    EXPECT_FALSE(library(2, 5) < 0);
}

// Ожидается исключение
TEST(MyTest, ThrowsException) {
    EXPECT_THROW(throw std::runtime_error("error"), std::runtime_error);
}

// ASSERT_EQ — как EXPECT_EQ, но при провале сразу останавливает тест
TEST(MyTest, AssertStopsOnFailure) {
    ASSERT_EQ(library(3, 4), 12); // если упадёт — следующие строки не выполнятся
    EXPECT_NE(library(3, 4), 0);
}