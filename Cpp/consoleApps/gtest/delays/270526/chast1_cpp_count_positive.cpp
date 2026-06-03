// Часть 1 — C++
// Функция countPositive() — считает количество положительных чисел в массиве.
// Unit-тесты с Google Test.

#include <gtest/gtest.h>
#include <vector>

int countPositive(const std::vector<int>& arr) {
    int count = 0;
    for (int n : arr) {
        if (n > 0) count++;
    }
    return count;
}

// Чек-лист:
// 1. Только положительные числа                  +
// 2. Только отрицательные числа → 0              +
// 3. Смешанные значения                          +
// 4. Наличие нулей (ноль не положительный)       +
// 5. Пустой массив → 0                          +
// 6. Один элемент — положительный                +
// 7. Один элемент — отрицательный                +

// Тест-кейсы:
// №  Входные данные           Ожидаемый  Описание
// 1  {1, 2, 3}                3          все положительные
// 2  {-1, -2, -3}             0          все отрицательные
// 3  {-1, 0, 1, 2}            2          смешанные + ноль
// 4  {0, 0, 0}                0          только нули
// 5  {}                       0          пустой массив
// 6  {42}                     1          один положительный
// 7  {-7}                     0          один отрицательный

TEST(CountPositiveTest, AllPositive) {
    EXPECT_EQ(countPositive({1, 2, 3}), 3);
}

TEST(CountPositiveTest, AllNegative) {
    EXPECT_EQ(countPositive({-1, -2, -3}), 0);
}

TEST(CountPositiveTest, Mixed) {
    EXPECT_EQ(countPositive({-1, 0, 1, 2}), 2);
}

TEST(CountPositiveTest, OnlyZeros) {
    EXPECT_EQ(countPositive({0, 0, 0}), 0);
}

TEST(CountPositiveTest, EmptyArray) {
    EXPECT_EQ(countPositive({}), 0);
}

TEST(CountPositiveTest, SinglePositive) {
    EXPECT_EQ(countPositive({42}), 1);
}

TEST(CountPositiveTest, SingleNegative) {
    EXPECT_EQ(countPositive({-7}), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
