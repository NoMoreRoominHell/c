#include <stdio.h>
#include <windows.h>
#include "hello.h"

int main() {
    // 设置 Windows 控制台输出编码为 UTF-8 (65001)，完美防止中文输出乱码！
    SetConsoleOutputCP(CP_UTF8);
    
    printf("=== CMake Hello World Demo ===\n");
    
    // 调用封装的模块函数
    print_hello("Antigravity IDE 开发者");

    for(int i = 0; i < 10; i++) {
        printf("i = %d\n", i);
    }
    
    return 0;
}
