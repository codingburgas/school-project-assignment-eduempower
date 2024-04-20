#include "homePage.h"
#include "courses.h"

void homePage() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/background_1.png");

    Texture2D button1Background = LoadTexture("../resources/button1_background.png");
    Texture2D button2Background = LoadTexture("../resources/button2_background.png");
    Texture2D button3Background = LoadTexture("../resources/button3_background.png");

    const int buttonWidth = 587;
    const int buttonHeight = 105;
    const int buttonSpacing = 60;

    const int totalButtonHeight = buttonHeight * 3 + buttonSpacing * 2;
    const int buttonX = (screenWidth - buttonWidth) / 2;
    const int buttonYStart = (screenHeight - totalButtonHeight) / 2 + 160;

    Rectangle button1Rec = { buttonX, buttonYStart, buttonWidth, buttonHeight };
    Rectangle button2Rec = { buttonX, buttonYStart + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };
    Rectangle button3Rec = { buttonX, buttonYStart + (buttonHeight + buttonSpacing) * 2, buttonWidth, buttonHeight };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(button1Background, buttonX, buttonYStart, WHITE);
        DrawTexture(button2Background, buttonX, buttonYStart + buttonHeight + buttonSpacing, WHITE);
        DrawTexture(button3Background, buttonX, buttonYStart + (buttonHeight + buttonSpacing) * 2, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonYStart, buttonWidth, buttonHeight })) {
            CloseWindow();
            Courses();
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonYStart + buttonHeight + buttonSpacing, buttonWidth, buttonHeight })) {
            CloseWindow();
            Courses();
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonYStart + (buttonHeight + buttonSpacing) * 2, buttonWidth, buttonHeight })) {
            CloseWindow();
        }

        if (CheckCollisionPointRec(GetMousePosition(), button1Rec))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else if (CheckCollisionPointRec(GetMousePosition(), button2Rec))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else if (CheckCollisionPointRec(GetMousePosition(), button3Rec))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(button1Background);
    UnloadTexture(button2Background);
    UnloadTexture(button3Background);

    CloseWindow();
}