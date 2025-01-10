# 包含 Google Test 的头文件和库路径
include_directories(${CMAKE_SOURCE_DIR}/src/lib/googletest/gtest/include)
link_directories(${CMAKE_SOURCE_DIR}/src/lib/googletest/gtest/lib)

# 添加测试目标
add_executable(test_add test_add.cpp)
target_link_libraries(test_add PRIVATE gtest gtest_main calculate)

add_executable(test_sub test_sub.cpp)
target_link_libraries(test_sub PRIVATE gtest gtest_main calculate)

add_executable(test_log_manage test_log_manage.cpp)
target_link_libraries(test_log_manage PRIVATE gtest gtest_main utils)

# 使用 Google Test 的 CTest 集成
include(GoogleTest)
gtest_discover_tests(test_add)
gtest_discover_tests(test_sub)
gtest_discover_tests(test_log_manage)

# 注册测试到 CTest
add_test(NAME TestAdd COMMAND test_add)
add_test(NAME TestSub COMMAND test_sub)
add_test(NAME TestLogManage COMMAND test_log_manage)
