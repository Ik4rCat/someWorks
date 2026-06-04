// Часть 4 (050626) — Поддержка и тестирование
// Функция: findMin() — минимальный элемент массива
// Google Test

// Чек-лист:
// [x] Массив из одного элемента → он и есть минимум
// [x] Отрицательные значения → корректный минимум
// [x] Одинаковые элементы → любой из них
// [x] Большие числа → корректный результат
// [x] Пустой массив → INT_MAX (или исключение)

#include <gtest/gtest.h>
#include <vector>
#include <climits>

int findMin(const std::vector<int>& arr) {
    if (arr.empty()) return INT_MAX;
    int min = arr[0];
    for (int x : arr)
        if (x < min) min = x;
    return min;
}

// Test cases:
// | # | Входные данные          | Ожидаемый  | Описание              |
// |---|-------------------------|------------|-----------------------|
// | 1 | {42}                    | 42         | Один элемент          |
// | 2 | {-5, -1, -3}            | -5         | Отрицательные         |
// | 3 | {7, 7, 7}               | 7          | Одинаковые элементы   |
// | 4 | {1000000, 999999}       | 999999     | Большие числа         |
// | 5 | {}                      | INT_MAX    | Пустой массив         |
// | 6 | {3, 1, 4, 1, 5, 9}      | 1          | Обычный список        |
// | 7 | {0, -1, 1}              | -1         | С нулём               |

TEST(FindMinTest, SingleElement) {
    EXPECT_EQ(findMin({42}), 42);
}

TEST(FindMinTest, NegativeValues) {
    EXPECT_EQ(findMin({-5, -1, -3}), -5);
}

TEST(FindMinTest, AllSame) {
    EXPECT_EQ(findMin({7, 7, 7}), 7);
}

TEST(FindMinTest, LargeNumbers) {
    EXPECT_EQ(findMin({1000000, 999999}), 999999);
}

TEST(FindMinTest, EmptyArray) {
    EXPECT_EQ(findMin({}), INT_MAX);
}

TEST(FindMinTest, Normal) {
    EXPECT_EQ(findMin({3, 1, 4, 1, 5, 9}), 1);
}

TEST(FindMinTest, WithZero) {
    EXPECT_EQ(findMin({0, -1, 1}), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
