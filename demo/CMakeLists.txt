cmake_minimum_required(VERSION 3.15)

# 1. 设置项目名称和支持的语言 (C语言)
project(HelloWorldDemo C)

# 2. 设置 C 语言标准 (例如 C99 或 C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 针对 MSVC 编译器开启 UTF-8 编码支持，消除 C4819 警告并防止乱码
if(MSVC)
    add_compile_options(/utf-8)
endif()

# 3. 添加生成可执行文件 target
# 语法: add_executable(<生成的可执行文件名> <源代码文件1> <源代码文件2> ...)
add_executable(demo_app 
    src/main.c
    src/hello.c
)

# 4. 指定头文件搜索路径 (-I 选项)
# 这样源代码里就可以直接 #include "hello.h"，而无需写完整相对路径 src/../include/hello.h
target_include_directories(demo_app PRIVATE include)

# 5. 自动通过 vcpkg 寻找并链接 C 语言轻量 GUI 库 (raylib)
find_package(raylib CONFIG REQUIRED)
target_link_libraries(demo_app PRIVATE raylib)
