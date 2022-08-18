target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day01.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/day02.cpp
)

target_include_directories(events PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")