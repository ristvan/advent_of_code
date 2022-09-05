target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day06.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/helpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lightgrid.cpp
)

target_include_directories(events PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(
    aoc_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/helpers.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lightgrid.test.cpp
)
target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
