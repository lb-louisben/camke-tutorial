add_library(utils
    print/array_print.cpp
    log/log_manage.cpp
)

target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/print
    ${CMAKE_CURRENT_SOURCE_DIR}/log
)

# 链接 calculate 模块
target_link_libraries(utils PUBLIC calculate)
