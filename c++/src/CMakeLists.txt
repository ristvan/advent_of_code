configure_file(version.hpp.in version.hpp)

add_executable(aoc aoc.cpp)

target_include_directories(aoc PUBLIC "${PROJECT_BINARY_DIR}")