// Часть 3 (050626) — Поддержка и тестирование
// Функция: sumEven() — сумма чётных чисел массива
// Google Test

// Чек-лист:
// [x] Только чётные числа → сумма всех
// [x] Только нечётные числа → 0
// [x] Отрицательные чётные → учитываются
// [x] Пустой массив → 0
// [x] Наличие нулей → 0 чётное, включается в сумму

#include <gtest/gtest.h>
#include <vector>

int sumEven(const std::vector<int>& arr) {
    int sum = 0;
    for (int x : arr)
        if (x % 2 == 0) sum += x;
    return sum;
}

// Test cases:
// | # | Входные данные        | Ожидаемый | Описание              |
// |---|-----------------------|-----------|-----------------------|
// | 1 | {2, 4, 6}             | 12        | Только чётные         |
// | 2 | {1, 3, 5}             | 0         | Только нечётные       |
// | 3 | {-2, -4, 1}           | -6        | Отрицательные чётные  |
// | 4 | {}                    | 0         | Пустой массив         |
// | 5 | {0, 1, 2}             | 2         | Нуль в массиве        |
// | 6 | {1, 2, 3, 4}          | 6         | Смешанный             |
// | 7 | {0, 0, 0}             | 0         | Только нули           |

TEST(SumEvenTest, OnlyEven) {
    EXPECT_EQ(sumEven({2, 4, 6}), 12);
}

TEST(SumEvenTest, OnlyOdd) {
    EXPECT_EQ(sumEven({1, 3, 5}), 0);
}

TEST(SumEvenTest, NegativeEven) {
    EXPECT_EQ(sumEven({-2, -4, 1}), -6);
}

TEST(SumEvenTest, EmptyArray) {
    EXPECT_EQ(sumEven({}), 0);
}

TEST(SumEvenTest, WithZero) {
    EXPECT_EQ(sumEven({0, 1, 2}), 2);
}

TEST(SumEvenTest, Mixed) {
    EXPECT_EQ(sumEven({1, 2, 3, 4}), 6);
}

TEST(SumEvenTest, OnlyZeros) {
    EXPECT_EQ(sumEven({0, 0, 0}), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
