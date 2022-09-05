target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day07.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rshiftop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lshiftop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/number.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/variable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/notop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/andop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/orop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/translator.cpp
)

target_include_directories(events PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(
    aoc_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/translator.test.cpp
)
target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")