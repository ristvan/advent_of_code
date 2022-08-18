add_library(events event.cpp)

target_include_directories(
    events
    PUBLIC "${CMAKE_SOURCE_DIR}/src"
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
