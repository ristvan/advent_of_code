add_library(events STATIC event.cpp)
add_subdirectory(2015)

target_include_directories(
    events
    PUBLIC "${CMAKE_SOURCE_DIR}/src"
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
