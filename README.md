# CMake Tutorial
# CMake 学习指南

从最简单的项目到复杂的框架逻辑，本指南将逐步带领您了解如何使用 CMake 构建、管理和测试项目。

## 目录
1. [CMake 简介](#cmake-%E7%AE%80%E4%BB%8B)
2. [最简单的 CMake 示例](#%E6%9C%80%E7%AE%80%E5%8D%95%E7%9A%84-cmake-%E7%A4%BA%E4%BE%8B)
3. [模块化项目结构](#%E6%A8%A1%E5%9D%97%E5%8C%96%E9%A1%B9%E7%9B%AE%E7%BB%93%E6%9E%84)
4. [添加测试](#%E6%B7%BB%E5%8A%A0%E6%B5%8B%E8%AF%95)
5. [最终的复杂框架逻辑](#%E6%9C%80%E7%BB%88%E7%9A%84%E5%A4%8D%E6%9D%82%E6%A1%86%E6%9E%B6%E9%80%BB%E8%BE%91)
6. [常见问题解答](#%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E8%A7%A3%E7%AD%94)
7. [CMake 常用命令黄页](#cmake-%E5%B8%B8%E7%94%A8%E5%91%BD%E4%BB%A4%E9%BB%84%E9%A1%B5)

---

## CMake 简介

CMake 是一个跨平台的构建工具，主要用于生成原生的构建系统文件，例如 Makefile 或 Visual Studio 工程文件。它的核心思想是通过一个 `CMakeLists.txt` 文件描述项目的构建逻辑。

核心功能：
- **跨平台支持**：支持 Linux、Windows、macOS。
- **灵活配置**：适用于从简单项目到复杂项目的各种需求。
- **模块化支持**：可以轻松管理子模块和依赖关系。
- **支持测试**：通过 CTest 与 Google Test 等测试框架集成。

---

## 最简单的 CMake 示例

### 1. 项目结构
```plaintext
simple_project/
├── CMakeLists.txt
├── main.cpp
```

### 2. `main.cpp`
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, CMake!" << std::endl;
    return 0;
}
```

### 3. `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.10)
project(SimpleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SimpleExecutable main.cpp)
```

### 4. 构建与运行
```bash
mkdir build && cd build
cmake ..
make
./SimpleExecutable
```
输出：
```plaintext
Hello, CMake!
```

---

## 模块化项目结构

随着项目规模的增长，将代码模块化非常重要。

### 1. 项目结构
```plaintext
modular_project/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   ├── add.cpp
│   ├── add.h
│   ├── sub.cpp
│   ├── sub.h
│   └── main.cpp
```

### 2. `src/add.cpp` 和 `src/add.h`
```cpp
// add.h
#ifndef ADD_H
#define ADD_H
int add(int a, int b);
#endif

// add.cpp
#include "add.h"
int add(int a, int b) {
    return a + b;
}
```

### 3. `src/sub.cpp` 和 `src/sub.h`
```cpp
// sub.h
#ifndef SUB_H
#define SUB_H
int sub(int a, int b);
#endif

// sub.cpp
#include "sub.h"
int sub(int a, int b) {
    return a - b;
}
```

### 4. `src/main.cpp`
```cpp
#include <iostream>
#include "add.h"
#include "sub.h"

int main() {
    int a = 10, b = 5;
    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a - b = " << sub(a, b) << std::endl;
    return 0;
}
```

### 5. 顶层 `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.10)
project(ModularProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
```

### 6. `src/CMakeLists.txt`
```cmake
add_library(add add.cpp)
add_library(sub sub.cpp)

add_executable(ModularExecutable main.cpp)
target_link_libraries(ModularExecutable PRIVATE add sub)
```

### 7. 构建与运行
```bash
mkdir build && cd build
cmake ..
make
./src/ModularExecutable
```
输出：
```plaintext
a + b = 15
a - b = 5
```

---

## 添加测试

引入测试框架，例如 Google Test，可以帮助确保代码的正确性。

### 1. 项目结构
```plaintext
project_with_tests/
├── CMakeLists.txt
├── src/
│   ├── ... (和上面相同)
├── tests/
│   ├── CMakeLists.txt
│   ├── test_add.cpp
│   └── test_sub.cpp
```

### 2. `tests/test_add.cpp`
```cpp
#include <gtest/gtest.h>
#include "add.h"

TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(add(2, 3), 5);
}
```

### 3. `tests/test_sub.cpp`
```cpp
#include <gtest/gtest.h>
#include "sub.h"

TEST(SubTest, HandlesPositiveInput) {
    EXPECT_EQ(sub(5, 3), 2);
}
```

### 4. `tests/CMakeLists.txt`
```cmake
add_executable(test_add test_add.cpp)
target_link_libraries(test_add PRIVATE gtest gtest_main add)

gtest_discover_tests(test_add)

add_executable(test_sub test_sub.cpp)
target_link_libraries(test_sub PRIVATE gtest gtest_main sub)

gtest_discover_tests(test_sub)
```

### 5. 在顶层 `CMakeLists.txt` 中添加测试
```cmake
enable_testing()
add_subdirectory(tests)
```

### 6. 构建与运行测试
```bash
mkdir build && cd build
cmake ..
make
ctest
```

---

## 最终的复杂框架逻辑

整合模块化代码与测试，形成清晰的项目架构：
```plaintext
complex_project/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   ├── add/
│   │   ├── add.cpp
│   │   ├── add.h
│   ├── sub/
│   │   ├── sub.cpp
│   │   ├── sub.h
│   ├── main.cpp
├── tests/
│   ├── CMakeLists.txt
│   ├── test_add.cpp
│   ├── test_sub.cpp
```

> **注**：在 `src` 和 `tests` 中分别设置子目录和构建逻辑，保证模块化和测试的独立性。

---

## 常见问题解答

### 1. 为什么要使用 `add_subdirectory`？
它可以递归地添加子目录，保持顶层 `CMakeLists.txt` 简洁，并允许模块化管理。

### 2. `target_include_directories` 和 `include_directories` 有什么区别？
- `target_include_directories` 是针对特定目标设置头文件路径，推荐使用。
- `include_directories` 是全局作用，可能导致头文件冲突。

### 3. 如何避免 `ld: warning: ignoring duplicate libraries`？
确保在 `target_link_libraries` 中每个目标只链接一次相关库。

### 4. 如何重新运行 CMake？
删除 `build` 文件夹并重新生成：
```bash
rm -rf build
mkdir build
cd build
cmake ..
```

---

## CMake 常用命令黄页

#### **1. 基础命令**
- **`project()`**：定义项目名称和支持的语言。
  ```cmake
  project(MyProject LANGUAGES CXX)
  ```

- **`cmake_minimum_required()`**：设置 CMake 最低版本要求。
  ```cmake
  cmake_minimum_required(VERSION 3.10)
  ```

- **`add_executable()`**：定义可执行文件。
  ```cmake
  add_executable(my_program main.cpp)
  ```

- **`add_library()`**：定义静态或动态库。
  ```cmake
  add_library(my_library STATIC library.cpp)
  ```

#### **2. 路径管理**
- **`target_include_directories()`**：为目标指定头文件路径。
  ```cmake
  target_include_directories(my_program PRIVATE include/)
  ```

- **`target_link_libraries()`**：为目标链接依赖库。
  ```cmake
  target_link_libraries(my_program PRIVATE my_library)
  ```

- **`include_directories()`**：设置全局头文件路径（不推荐）。
  ```cmake
  include_directories(include/)
  ```

#### **3. 变量设置**
- **`set()`**：定义变量。
  ```cmake
  set(CMAKE_CXX_STANDARD 17)
  ```

- **`message()`**：打印信息，常用于调试。
  ```cmake
  message("Build started")
  ```

#### **4. 测试相关**
- **`enable_testing()`**：启用测试功能。
  ```cmake
  enable_testing()
  ```

- **`add_test()`**：注册测试。
  ```cmake
  add_test(NAME MyTest COMMAND my_test_executable)
  ```

- **`include(GoogleTest)`**：使用 Google Test 集成。
  ```cmake
  include(GoogleTest)
  ```

#### **5. 高级功能**
- **`add_subdirectory()`**：递归添加子目录。
  ```cmake
  add_subdirectory(src)
  ```

- **`aux_source_directory()`**：自动收集目录中的所有源文件（不推荐）。
  ```cmake
  aux_source_directory(src DIR_SRCS)
  ```

- **`file(GLOB)`**：收集指定目录中的文件。
  ```cmake
  file(GLOB SRC_FILES "src/*.cpp")
  ```

- **`find_package()`**：查找外部依赖包。
  ```cmake
  find_package(Boost REQUIRED)
  ```

- **`configure_file()`**：配置并复制文件到构建目录。
  ```cmake
  configure_file(config.h.in config.h)
  ```

#### **6. 调试相关**
- **`message(STATUS ...)`**：输出状态信息。
  ```cmake
  message(STATUS "This is a status message.")
  ```

- **`message(WARNING ...)`**：输出警告信息。
  ```cmake
  message(WARNING "This is a warning message.")
  ```

- **`message(FATAL_ERROR ...)`**：输出错误并中止配置。
  ```cmake
  message(FATAL_ERROR "Configuration failed.")
  ```

#### **7. 版本控制**
- **`set_property()` 和 `get_property()`**：设置和获取目标属性。
  ```cmake
  set_property(TARGET my_program PROPERTY CXX_STANDARD 17)
  get_property(VAR TARGET my_program PROPERTY CXX_STANDARD)
  ```

- **`option()`**：定义可选项。
  ```cmake
  option(USE_FEATURE "Enable this feature" ON)
  ```