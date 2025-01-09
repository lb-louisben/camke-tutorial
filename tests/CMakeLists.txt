# 设置 Google Test 的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest/lib)

# 启用测试支持
enable_testing()

# 确保使用 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加测试
add_executable(test_add test_add.cpp)
target_link_libraries(test_add PRIVATE gtest_main calculate utils)

add_executable(test_sub test_sub.cpp)
target_link_libraries(test_sub PRIVATE gtest_main calculate utils)

add_executable(test_log_manage test_log_manage.cpp)
target_link_libraries(test_log_manage PRIVATE gtest_main utils)

# 使用 Google Test 的 CTest 集成
include(GoogleTest)
gtest_discover_tests(test_add)
gtest_discover_tests(test_sub)
gtest_discover_tests(test_log_manage)
