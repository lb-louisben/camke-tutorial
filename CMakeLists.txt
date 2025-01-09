# 最低CMake版本要求
cmake_minimum_required(VERSION 3.0)

# 定义项目
project(CALC LANGUAGES C CXX VERSION 1.0.4)

# 设置 C 标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加 src 文件夹
add_subdirectory(src)

# 添加测试子目录
add_subdirectory(tests)

# 指定最终生成的可执行文件
add_executable(main src/main.c)

# 链接子模块库到主程序
target_link_libraries(main calculate utils)

# 添加头文件搜索路径
target_include_directories(main PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/add
    ${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/sub
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/print
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log
)

# 调试输出头文件路径
message("Include directories:")
message("${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/add")
message("${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/sub")
message("${CMAKE_CURRENT_SOURCE_DIR}/src/utils/print")
message("${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log")