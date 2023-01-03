target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day08.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/matchsticker.cpp
)

target_include_directories(events PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(
    aoc_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/matchsticker.test.cpp
)

target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
