#include <gtest/gtest.h>
#include <vector>

int countEven(const std::vector<int>& arr) {
    int count = 0;
    for (int n : arr) {
        if (n % 2 == 0) count++;
    }
    return count;
}

TEST(CountEvenTest, EmptyArray) {
    EXPECT_EQ(countEven({}), 0);
}

TEST(CountEvenTest, WithZero) {
    EXPECT_EQ(countEven({0, 1, 3}), 1);
}

TEST(CountEvenTest, AllEven) {
    EXPECT_EQ(countEven({2, 4, 6, 8}), 4);
}

TEST(CountEvenTest, AllOdd) {
    EXPECT_EQ(countEven({1, 3, 5, 7}), 0);
}

TEST(CountEvenTest, NegativeEven) {
    EXPECT_EQ(countEven({-2, -4, 1}), 2);
}

TEST(CountEvenTest, Mixed) {
    EXPECT_EQ(countEven({1, 2, 3, 4, 5}), 2);
}

TEST(CountEvenTest, SingleEven) {
    EXPECT_EQ(countEven({4}), 1);
}

TEST(CountEvenTest, SingleOdd) {
    EXPECT_EQ(countEven({7}), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
