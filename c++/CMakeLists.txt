cmake_minimum_required(VERSION 3.10)

project(aoc VERSION 0.7.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_subdirectory(common)
add_subdirectory(src)

#enable_testing()

#add_executable(
#    aoc_test
#    day05.cpp
#    day05.test.cpp
#    day06.cpp
#    day06.test.cpp
#)

#target_link_libraries(
#    aoc_test
#    gtest
#    gtest_main
#    pthread
#)

#include(GoogleTest)
#gtest_discover_tests(aoc_test)

