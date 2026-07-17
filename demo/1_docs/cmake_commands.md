# CMake 常用命令与开发速查手册

本手册分为两大部分：**终端命令行操作速查**（你每天在终端里敲的命令）和 **CMakeLists.txt 语法指令速查**（你每天写在配置文件里的语法）。

---

## 第一部分：终端命令行构建速查 (Terminal Commands)

绝大多数 C/C++ 现代项目的构建流程都遵循经典的 **“配置 -> 编译 -> 运行”** 三步走策略。

### 1. 基础构建三步走 (通用)

在项目根目录下（存在 `CMakeLists.txt` 的目录）执行：

```powershell
# 1. 配置 (Configure)：读取 CMakeLists.txt，在 build 文件夹下生成构建系统配置
cmake -B build

# 2. 编译 (Build)：自动调用底层编译器/构建工具，开始编译生成二进制可执行文件
cmake --build build

# 3. 运行 (Run)：运行生成出来的应用程序
.\build\demo_app.exe
# （如果是 Visual Studio MSVC 编译器，可执行文件一般在 .\build\Debug\demo_app.exe）
```

---

### 2. 指定特定的构建系统生成器 (`-G` 选项)

当你的电脑安装了多个编译器（如微软 MSVC、MinGW、Ninja）时，可以用 `-G` 参数显式指定生成何种工程：

#### 调用微软 Visual Studio 原生编译器 (MSVC)
```powershell
# 生成 Visual Studio 解决方案工程 (自动调用你电脑上的 VS)
cmake -B build -G "Visual Studio 18 2026" -A x64

# 或者如果你的系统装的是 VS 2022:
cmake -B build -G "Visual Studio 17 2022" -A x64

# 编译 Debug 或 Release 构建版本
cmake --build build --config Debug
cmake --build build --config Release
```

#### 调用极速构建工具 Ninja (跨平台极快)
```powershell
cmake -B build -G Ninja
cmake --build build
```

---

### 3. 日常维护命令（清理与重构）

```powershell
# 彻底清理已经编译的产物 (.o, .obj, .exe 等中间文件)，重新干净编译
cmake --build build --target clean

# 直接删除整个构建缓存文件夹 (遇到配置错乱时最为简单暴力且有效的方法)
Remove-Item -Recurse -Force build
```

---
---

## 第二部分：`CMakeLists.txt` 语法速查 (Syntax Reference)

### 1. 最小基本框架

每一个 `CMakeLists.txt` 的开头必须包含以下最基础的三行：

```cmake
# 1. 规定当前脚本兼容的最低 CMake 版本
cmake_minimum_required(VERSION 3.15)

# 2. 定义工程名称和所用的编程语言 (C 或 CXX 表示 C++)
project(MyAwesomeProject C)

# 3. 设定 C/C++ 标准 (例如 C11 或 C++17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
```

---

### 2. 生成目标：可执行程序与库 (`add_*`)

```cmake
# 生成可执行程序 (exe)
# 语法: add_executable(<目标名称> <源码1> <源码2> ...)
add_executable(demo_app 
    src/main.c
    src/hello.c
)

# 生成静态库 (.lib / .a)
add_library(my_math_lib STATIC src/math_utils.c)

# 生成动态链接库 (.dll / .so)
add_library(my_math_lib SHARED src/math_utils.c)
```

---

### 3. 头文件与宏定义 (`target_*`)

为指定的构建目标（如可执行程序或库）添加头文件搜索目录或预处理宏定义：

```cmake
# 指定头文件搜索目录 (-I)
# PRIVATE: 仅仅该可执行程序/模块自己使用这个头文件路径
# PUBLIC:  如果这是一个库，不仅库本身用，依赖这个库的其他目标也要用这个头文件路径
target_include_directories(demo_app PRIVATE include)

# 为程序添加编译宏定义 (-D)
# 例如：在 C 代码里可以通过 #ifdef DEBUG_MODE 来进行逻辑判断
target_compile_definitions(demo_app PRIVATE DEBUG_MODE=1)
```

---

### 4. 模块链接与外部依赖 (`target_link_libraries`)

将不同的模块、库或第三方静态/动态库链接到我们的主程序上：

```cmake
# 将静态库/动态库连接到我们的主可执行程序上
# 相当于编译时的 -l 选项
target_link_libraries(demo_app PRIVATE my_math_lib)
```

---

### 5. 跨文件夹模块管理 (多目录工程最佳实践)

在大型项目中，通常会将不同模块放到独立子文件夹，并在各个文件夹下写自己的 `CMakeLists.txt`：

```cmake
# 引入并编译子文件夹中的 CMake 模块 (例如子文件夹名叫 modules/network)
add_subdirectory(modules/network)

# 主程序链接子模块里定义的库
target_link_libraries(demo_app PRIVATE network_lib)
```

---

### 6. 调试小工具：打印输出与报错 (`message`)

在你觉得某部分构建逻辑不对劲，或者想看某个变量值的时候：

```cmake
# 打印普通调试提示信息
message(STATUS "当前系统的 C 编译器是: ${CMAKE_C_COMPILER}")

# 打印警告 (不中断运行)
message(WARNING "警告：未开启全优化选项")

# 打印错误并立刻强制停止构建 (中断命令)
message(FATAL_ERROR "严重错误：找不到必需的系统库！")
```
