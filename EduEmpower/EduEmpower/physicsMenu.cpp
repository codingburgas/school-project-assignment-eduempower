#include "physicsMenu.h"
#include "physicsTest1.h"
#include "physicsTest2.h"

int physicsMenu() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/background_physics_main_page.png");

    Texture2D courseButtonImg = LoadTexture("../resources/Course.png");
    Texture2D homeworkButtonImg = LoadTexture("../resources/Homework.png");
    Texture2D gradesButtonImg = LoadTexture("../resources/grades_text.png");

    Texture2D physicsButtonImg = LoadTexture("../resources/Physics.png");
    Texture2D lesson1ButtonImg = LoadTexture("../resources/Lesson1.png");
    Texture2D lesson2ButtonImg = LoadTexture("../resources/Lesson2.png");
    Texture2D lesson3ButtonImg = LoadTexture("../resources/Lesson3.png");

    Texture2D test1ButtonImg = LoadTexture("../resources/test1.png");
    Texture2D test2ButtonImg = LoadTexture("../resources/test2.png");

    Texture2D finalTestButtonImg = LoadTexture("../resources/finalTest.png");

    int yOffset = 60;
    int xOffsetPhysics = 145; // Top left corner
    int xOffsetOthers = screenWidth - courseButtonImg.width - 50; // Top right corner
    int buttonGap = 20;
    int lessonButtonGap = 30; // Gap between lesson buttons

    // Position of navigation buttons
    int courseButtonX = screenWidth - courseButtonImg.width - 50;
    int homeworkButtonX = courseButtonX - courseButtonImg.width - buttonGap;
    int gradesButtonX = homeworkButtonX - homeworkButtonImg.width - buttonGap;

    int xOffsetLessons = xOffsetPhysics + physicsButtonImg.width + buttonGap - 230; // Right of physics button
    int yOffsetLesson1 = yOffset + physicsButtonImg.height + buttonGap + 130;
    int yOffsetLesson2 = yOffsetLesson1 + lesson1ButtonImg.height + lessonButtonGap;
    int yOffsetLesson3 = yOffsetLesson2 + lesson2ButtonImg.height + lessonButtonGap;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(physicsButtonImg, xOffsetPhysics, yOffset, WHITE);

        // Logical error: right now the homeworkTextButton is overlapping the gradesTextButton
        // DrawTexture(courseButtonImg, courseButtonX, yOffset, WHITE);
        // DrawTexture(homeworkButtonImg, homeworkButtonX, yOffset, WHITE);
        // DrawTexture(gradesButtonImg, gradesButtonX, yOffset, WHITE);

        DrawTexture(lesson1ButtonImg, xOffsetLessons, yOffsetLesson1, WHITE);
        DrawTexture(lesson2ButtonImg, xOffsetLessons, yOffsetLesson2, WHITE);
        DrawTexture(lesson3ButtonImg, xOffsetLessons, yOffsetLesson3, WHITE);

        DrawTexture(test1ButtonImg, xOffsetOthers - 1590, yOffsetLesson1 + 340, WHITE);
        DrawTexture(test2ButtonImg, xOffsetOthers - 1590, yOffsetLesson2 + 360, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetPhysics, (float)yOffset, (float)physicsButtonImg.width, (float)physicsButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)courseButtonX, (float)yOffset, (float)courseButtonImg.width, (float)courseButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)homeworkButtonX, (float)yOffset, (float)homeworkButtonImg.width, (float)homeworkButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)gradesButtonX, (float)yOffset, (float)gradesButtonImg.width, (float)gradesButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson1, (float)lesson1ButtonImg.width, (float)lesson1ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson3, (float)lesson3ButtonImg.width, (float)lesson3ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height }) ||
            CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetPhysics, (float)yOffset, (float)physicsButtonImg.width, (float)physicsButtonImg.height })) {
            CloseWindow();
            physicsMenu();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson1, (float)lesson1ButtonImg.width, (float)lesson1ButtonImg.height })) {
            CloseWindow();
            InitWindow(screenWidth, screenHeight, "Lesson 1");
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height })) {
            CloseWindow();
            InitWindow(screenWidth, screenHeight, "Lesson 2");
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson3, (float)lesson3ButtonImg.width, (float)lesson3ButtonImg.height })) {
            CloseWindow();
            InitWindow(screenWidth, screenHeight, "Lesson 3");
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height })) {
            CloseWindow();
            physicsTest1();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
            CloseWindow();
            physicsTest2();
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(courseButtonImg);
    UnloadTexture(homeworkButtonImg);
    UnloadTexture(gradesButtonImg);
    UnloadTexture(physicsButtonImg);
    UnloadTexture(lesson1ButtonImg);
    UnloadTexture(lesson2ButtonImg);
    UnloadTexture(lesson3ButtonImg);
    UnloadTexture(test1ButtonImg);
    UnloadTexture(test2ButtonImg);
    UnloadTexture(finalTestButtonImg);

    CloseWindow();
    return 0;
}