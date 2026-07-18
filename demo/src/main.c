#include <raylib.h>

int main(void) {
    InitWindow(800, 450, "Hello, raylib!");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello, World!", 300, 200, 40, DARKGRAY);
        EndDrawing();
        // vcpkg raylib 6.0: SUPPORT_CUSTOM_FRAME_CONTROL requires manual calls
        PollInputEvents();
        SwapScreenBuffer();
    }

    CloseWindow();
    return 0;
}
