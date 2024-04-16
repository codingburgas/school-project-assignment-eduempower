#include "mainMenu.h"
#include "courses.h"

int mainMenu() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");

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
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonYStart + buttonHeight + buttonSpacing, buttonWidth, buttonHeight })) {
			CloseWindow();
			Courses();
		}
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonYStart + (buttonHeight + buttonSpacing) * 2, buttonWidth, buttonHeight })) {
			CloseWindow();
		}

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(button1Background);
    UnloadTexture(button2Background);
    UnloadTexture(button3Background);

    CloseWindow();

    return 0;
}