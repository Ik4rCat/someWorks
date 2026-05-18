cmake_minimum_required(VERSION 4.2)
project(180526)

set(CMAKE_CXX_STANDARD 20)

add_library(180526 STATIC library.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(my_tests tests/my_test.cpp)
target_link_libraries(my_tests GTest::gtest_main 180526)

include(GoogleTest)
gtest_discover_tests(my_tests)