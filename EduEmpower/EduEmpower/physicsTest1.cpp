#include "physicsTest1.h"
#include "physicsMenu.h"

void physicsTest1() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/test1_physics.png");

    // Load button textures
    Texture2D physicsButtonImg = LoadTexture("../resources/Physics.png");
    Texture2D lesson1ButtonImg = LoadTexture("../resources/Lesson1.png");
    Texture2D lesson2ButtonImg = LoadTexture("../resources/Lesson2.png");
    Texture2D test1ButtonImg = LoadTexture("../resources/test1.png");
    Texture2D test2ButtonImg = LoadTexture("../resources/test2.png");
    Texture2D finalTestButtonImg = LoadTexture("../resources/finalTest.png");

    int yOffset = 60;
    int xOffsetPhysics = 145; // Top left corner
    int xOffsetOthers = screenWidth - physicsButtonImg.width - 50; // Top right corner
    int buttonGap = 20;
    int lessonButtonGap = 40; // Gap between lesson buttons

    // Position of navigation buttons
    int physicsButtonX = screenWidth - physicsButtonImg.width - 50;

    int xOffsetLessons = xOffsetPhysics + physicsButtonImg.width + buttonGap - 230; // Right of physics button
    int yOffsetLesson1 = yOffset + physicsButtonImg.height + buttonGap + 150;
    int yOffsetLesson2 = yOffsetLesson1 + lesson1ButtonImg.height + lessonButtonGap;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(physicsButtonImg, xOffsetPhysics, yOffset, WHITE);
        DrawTexture(lesson1ButtonImg, xOffsetLessons, yOffsetLesson1, WHITE);
        DrawTexture(lesson2ButtonImg, xOffsetLessons, yOffsetLesson2, WHITE);
        DrawTexture(test1ButtonImg, xOffsetOthers - 1460, yOffsetLesson1 + 340, WHITE);
        DrawTexture(test2ButtonImg, xOffsetOthers - 1460, yOffsetLesson2 + 340, WHITE);
        DrawTexture(finalTestButtonImg, xOffsetOthers - 1500, yOffsetLesson2 + 500, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetPhysics, (float)yOffset, (float)physicsButtonImg.width, (float)physicsButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson1, (float)lesson1ButtonImg.width, (float)lesson1ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 380), (float)finalTestButtonImg.width, (float)finalTestButtonImg.height })) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        // Check for button clicks
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();

            // Check if any button is clicked
            if (CheckCollisionPointRec(mousePos, { (float)xOffsetPhysics, (float)yOffset, (float)physicsButtonImg.width, (float)physicsButtonImg.height })) {
                CloseWindow();
                physicsMenu();
            }
            else if (CheckCollisionPointRec(mousePos, { (float)xOffsetLessons, (float)yOffsetLesson1, (float)lesson1ButtonImg.width, (float)lesson1ButtonImg.height })) {
                CloseWindow();
                physicsLesson1();
            }
            else if (CheckCollisionPointRec(mousePos, { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height })) {
                CloseWindow();  
                physicsLesson2();
            }
            else if (CheckCollisionPointRec(mousePos, { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height })) {
            }
            else if (CheckCollisionPointRec(mousePos, { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
                CloseWindow();
                physicsTest2();
            }
            else if (CheckCollisionPointRec(mousePos, { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 380), (float)finalTestButtonImg.width, (float)finalTestButtonImg.height })) {
                CloseWindow();
				// physicsFinalTest();
            }
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(physicsButtonImg);
    UnloadTexture(lesson1ButtonImg);
    UnloadTexture(lesson2ButtonImg);
    UnloadTexture(test1ButtonImg);
    UnloadTexture(test2ButtonImg);
    UnloadTexture(finalTestButtonImg);

    CloseWindow();
}