#include <gtest/gtest.h>
#include <string>

std::string replaceChar(std::string s, char from, char to) {
    for (char& c : s) {
        if (c == from) c = to;
    }
    return s;
}

TEST(ReplaceCharTest, CharPresent) {
    EXPECT_EQ(replaceChar("hello", 'l', 'r'), "herro");
}

TEST(ReplaceCharTest, CharAbsent) {
    EXPECT_EQ(replaceChar("hello", 'z', 'x'), "hello");
}

TEST(ReplaceCharTest, EmptyString) {
    EXPECT_EQ(replaceChar("", 'a', 'b'), "");
}

TEST(ReplaceCharTest, SpecialChars) {
    EXPECT_EQ(replaceChar("a!b!c", '!', '-'), "a-b-c");
}

TEST(ReplaceCharTest, ReplaceWithSame) {
    EXPECT_EQ(replaceChar("aaa", 'a', 'a'), "aaa");
}

TEST(ReplaceCharTest, AllCharsMatch) {
    EXPECT_EQ(replaceChar("aaaa", 'a', 'b'), "bbbb");
}

TEST(ReplaceCharTest, SingleChar) {
    EXPECT_EQ(replaceChar("x", 'x', 'y'), "y");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
