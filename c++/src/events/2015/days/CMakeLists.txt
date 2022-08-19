target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day01.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/day02.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/day03.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/day04.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/day05.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/md5.cpp
)

target_include_directories(events PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")