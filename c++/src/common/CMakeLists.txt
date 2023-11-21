add_library(
    common
    STATIC
    file_handler.cpp
    string_manipulators.cpp
    permutations.cpp
)

target_include_directories(
    common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(
    aoc_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/string_manipulators.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/permutations.test.cpp
)
target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")