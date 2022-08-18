configure_file(version.hpp.in version.hpp)

add_subdirectory(events)

add_executable(aoc aoc.cpp)
target_include_directories(aoc PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(aoc events)
