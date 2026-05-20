#include <gtest/gtest.h>
#include <stdexcept>

#include "library.h"


struct ReverseTestData {
    std::string input;
    std::string expected;
    std::string test_name;
};

class ReverseTest : public ::testing::TestWithParam<ReverseTestData> {};

TEST_P(ReverseTest, Cases) {
    const ReverseTestData& params = GetParam();
    EXPECT_EQ(reverseString(params.input), params.expected)
        << "Ошибка на строке: " << params.input;
}

INSTANTIATE_TEST_SUITE_P(
    ReverseSuite, ReverseTest,
    ::testing::Values(
        ReverseTestData{"hello",   "olleh",   "Normal_string"},
        ReverseTestData{"",        "",        "Empty_string"},
        ReverseTestData{"a",       "a",       "Single_char"},
        ReverseTestData{"abc def", "fed cba", "With_spaces"}
    ),
    [](const ::testing::TestParamInfo<ReverseTestData>& info) {
        return info.param.test_name;
    }
);



struct SumTestData {
    std::vector<int> input;
    int expected;
    std::string test_name;
};

class SumTest : public ::testing::TestWithParam<SumTestData> {};

TEST_P(SumTest, Cases) {
    const SumTestData& params = GetParam();
    EXPECT_EQ(sumArray(params.input), params.expected);
}

INSTANTIATE_TEST_SUITE_P(
    SumSuite, SumTest,
    ::testing::Values(
        SumTestData{{1, 2, 3},    6,  "Positive_numbers"},
        SumTestData{{-1, -2, -3}, -6, "Negative_numbers"},
        SumTestData{{5},          5,  "Single_element"},
        SumTestData{{},           0,  "Empty_array"}
    ),
    [](const ::testing::TestParamInfo<SumTestData>& info) {
        return info.param.test_name;
    }
);



struct PrimeTestData {
    int input;
    bool expected;
    std::string test_name;
};

class PrimeTest : public ::testing::TestWithParam<PrimeTestData> {};

TEST_P(PrimeTest, Cases) {
    const PrimeTestData& params = GetParam();
    EXPECT_EQ(isPrime(params.input), params.expected)
        << "Ошибка на числе: " << params.input;
}

INSTANTIATE_TEST_SUITE_P(
    PrimeSuite, PrimeTest,
    ::testing::Values(
        PrimeTestData{2,  true,  "Two_is_prime"},
        PrimeTestData{7,  true,  "Seven_is_prime"},
        PrimeTestData{8,  false, "Eight_not_prime"},
        PrimeTestData{1,  false, "One_not_prime"},
        PrimeTestData{-5, false, "Negative_not_prime"}
    ),
    [](const ::testing::TestParamInfo<PrimeTestData>& info) {
        return info.param.test_name;
    }
);



struct AvgTestData {
    std::vector<int> input;
    double expected;
    std::string test_name;
};

class AvgTest : public ::testing::TestWithParam<AvgTestData> {};

TEST_P(AvgTest, Cases) {
    const AvgTestData& params = GetParam();
    EXPECT_DOUBLE_EQ(average(params.input), params.expected);
}

TEST(AvgTest, EmptyThrows) {
    EXPECT_THROW(average({}), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(
    AvgSuite, AvgTest,
    ::testing::Values(
        AvgTestData{{2, 4, 6}, 4.0, "Three_elements"},
        AvgTestData{{1, 2},    1.5, "Two_elements"},
        AvgTestData{{5},       5.0, "Single_element"}
    ),
    [](const ::testing::TestParamInfo<AvgTestData>& info) {
        return info.param.test_name;
    }
);
