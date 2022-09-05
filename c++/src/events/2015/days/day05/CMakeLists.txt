target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day05.cpp
)

target_include_directories(events PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(
    aoc_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day05.test.cpp
)
target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
