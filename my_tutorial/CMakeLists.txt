# 最低CMake版本要求
cmake_minimum_required(VERSION 3.0)

project(CALC LANGUAGES CXX VERSION 1.3.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 启用测试支持
enable_testing()

# 添加 src 文件夹
add_subdirectory(src)

# 添加测试子目录
add_subdirectory(tests)

# 指定最终生成的可执行文件
add_executable(main src/main.cpp)

# 链接子模块库到主程序
target_link_libraries(main PRIVATE calculate utils)

# 添加头文件搜索路径
target_include_directories(main PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/add
    ${CMAKE_CURRENT_SOURCE_DIR}/src/calculate/sub
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/print
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log
)