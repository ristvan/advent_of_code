add_library(
    common
    STATIC
    file_handler.cpp
)

target_include_directories(
    common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)