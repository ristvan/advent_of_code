add_subdirectory(days)

target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/factory.cpp
)

target_include_directories(events PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")