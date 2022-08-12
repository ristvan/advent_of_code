cmake_minimum_required(VERSION 3.10)
project(aoc)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    aoc
    main.cpp event.cpp day01.cpp day02.cpp day03.cpp day04.cpp day05.cpp md5.cpp
    day06.cpp
)

enable_testing()

add_executable(
    aoc_test
    day05.cpp
    day05.test.cpp
    day06.cpp
    day06.test.cpp
)

target_link_libraries(
    aoc_test
    gtest
    gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(aoc_test)
