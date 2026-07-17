#include <stdio.h>
#include <windows.h>
#include <raylib.h> // 1. 引入纯 C GUI 图形界面头文件！
#include "hello.h"

int main() {
    // 设置 Windows 控制台输出编码为 UTF-8 (65001)，完美防止中文输出乱码！
    SetConsoleOutputCP(CP_UTF8);
    
    printf("=== CMake + raylib GUI Demo ===\n");
    print_hello("Antigravity IDE 开发者");

    // 2. 创建一个宽 800、高 450 的 GUI 图形窗口
    InitWindow(800, 450, "C语言 + raylib 极速图形界面 Demo");
    SetTargetFPS(60); // 锁定帧率为 60 帧

    // 3. 交互主循环：只要用户没用鼠标点击右上角的 X 关闭窗口，就不停刷新绘制
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); // 将背景涂成亮亮干净的白底
            
            // 在窗口正中间区域绘制文字提示与交互效果
            DrawText("Hello, Antigravity IDE!", 200, 160, 35, LIGHTGRAY);
            DrawText("Congratulations! Your raylib C GUI window works!", 140, 220, 20, DARKGRAY);
            DrawText("Press ESC or click [X] to close window", 230, 280, 16, MAROON);
        EndDrawing();
    }

    // 4. 关闭并回收图形窗口资源
    CloseWindow();
    return 0;
}
