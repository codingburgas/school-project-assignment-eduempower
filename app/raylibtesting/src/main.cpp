#include <raylib.h>

int main()
{
    Color darkGreen = Color{ 20, 160, 133, 255 };
    Color green = { 20, 160, 133, 255 };

    const int screenWidth = 800;
    const int screenHeight = 800;

    int ballX = 400;
    int ballY = 400;


    InitWindow(screenWidth, screenHeight, "App");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) {
            ballX += 3;
        }
        else if (IsKeyDown(KEY_LEFT)) {
            ballX -= 3;
        }
        else if (IsKeyDown(KEY_UP)) {
            ballY -= 3;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            ballY += 3;
        }

        BeginDrawing();
        ClearBackground(green);
        DrawCircle(ballX, ballY, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}