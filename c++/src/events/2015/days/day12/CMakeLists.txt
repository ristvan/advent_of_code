target_sources(
    events
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/day12.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NumberCounter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NotRedNumberCounter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JsonIterator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JsonPrinter.cpp
)

target_include_directories(events PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

# target_sources(
#     aoc_test
#     PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/tools.test.cpp
# )

# target_include_directories(aoc_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
