# 最低CMake版本要求
cmake_minimum_required(VERSION 3.20)

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

# 配置文件生成
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

# 指定最终生成的可执行文件
add_executable(main src/main.cpp)

# 添加生成目录为头文件路径
target_include_directories(main PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# 设置不同模式的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# 定义不同模式的编译选项
target_compile_options(main PRIVATE
    $<$<CONFIG:Debug>:-g -O0>
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
)

# 链接子模块库到主程序
target_link_libraries(main PRIVATE utils)
