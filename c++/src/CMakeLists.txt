configure_file(version.hpp.in version.hpp)


add_executable(aoc aoc.cpp)
target_include_directories(aoc PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(aoc events)

enable_testing()

add_executable(aoc_test "")

add_subdirectory(events)

target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(
   aoc_test
   gtest
   gtest_main
   pthread
)

include(GoogleTest)
gtest_discover_tests(aoc_test)
