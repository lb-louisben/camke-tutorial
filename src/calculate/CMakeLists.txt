add_library(calculate
    add/add.c
    sub/sub.c
)

target_include_directories(calculate PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/add
    ${CMAKE_CURRENT_SOURCE_DIR}/sub
)
