#include "physicsTest1.h"
#include "physicsMenu.h"

void physicsTest1() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/test1_physics.png");
    Texture2D physicsButtonImg = LoadTexture("../resources/Physics_yellow.png");

    int buttonWidth = physicsButtonImg.width;
    int buttonHeight = physicsButtonImg.height;
    int buttonPadding = 20; // Padding from the top and right edges
    int buttonX = screenWidth - buttonWidth - buttonPadding - 30; // X-coordinate
    int buttonY = buttonPadding + 5; // Y-coordinate


    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        DrawTextureRec(physicsButtonImg, {0, 0, 0, 0}, {145, 60}, WHITE);

        DrawTexture(physicsButtonImg, buttonX, buttonY, WHITE);

        EndDrawing();
    }
    CloseWindow();

    UnloadTexture(background);
    UnloadTexture(physicsButtonImg);
}