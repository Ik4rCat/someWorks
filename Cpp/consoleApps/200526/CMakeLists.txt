cmake_minimum_required(VERSION 3.14)
project(180526)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_library(180526 STATIC library.cpp)

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::GTest GTest::Main 180526)

include(GoogleTest)
gtest_discover_tests(tests)