add_library(calculate
    add/add.cpp
    sub/sub.cpp
)

target_include_directories(calculate PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/add
    ${CMAKE_CURRENT_SOURCE_DIR}/sub
)
