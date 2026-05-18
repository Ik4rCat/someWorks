#include <gtest/gtest.h>
#include <stdexcept>

#include "../library.h"

TEST(MyTest, Equal) {
    EXPECT_EQ(library(3, 4), 12);
}

TEST(MyTest, NotEqual) {
    EXPECT_NE(library(3, 4), 0);
}

TEST(MyTest, True) {
    EXPECT_TRUE(library(2, 5) > 0);
}

TEST(MyTest, False) {
    EXPECT_FALSE(library(2, 5) < 0);
}

TEST(MyTest, ThrowsException) {
    EXPECT_THROW(throw std::runtime_error("error"), std::runtime_error);
}

TEST(MyTest, AssertStopsOnFailure) {
    ASSERT_EQ(library(3, 4), 12);
    EXPECT_NE(library(3, 4), 0);
}