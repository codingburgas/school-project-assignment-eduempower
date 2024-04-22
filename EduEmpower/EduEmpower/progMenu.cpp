#include "progMenu.h"

int progMenu() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/bg-programming-menu.png");

    Texture2D courseButtonImg = LoadTexture("../resources/Course.png");
    Texture2D homeworkButtonImg = LoadTexture("../resources/Homework.png");
    Texture2D gradesButtonImg = LoadTexture("../resources/grades_text.png");

    Texture2D progButtonImg = LoadTexture("../resources/Programming_in_C++.png");
    Texture2D lesson1ButtonImg = LoadTexture("../resources/Lesson1.png");
    Texture2D lesson2ButtonImg = LoadTexture("../resources/Lesson2.png");
    Texture2D lesson3ButtonImg = LoadTexture("../resources/Lesson3.png");

    Texture2D test1ButtonImg = LoadTexture("../resources/test1.png");
    Texture2D test2ButtonImg = LoadTexture("../resources/test2.png");

    Texture2D finalTestButtonImg = LoadTexture("../resources/finalTest.png");

    int yOffset = 60;
    int xOffsetProg = 110; // Top left corner
    int xOffsetOthers = screenWidth - courseButtonImg.width - 50; // Top right corner
    int buttonGap = 20;
    int lessonButtonGap = 40; // Gap between lesson buttons

    // Position of navigation buttons
    int courseButtonX = screenWidth - courseButtonImg.width - 20;
    int homeworkButtonX = courseButtonX - courseButtonImg.width - buttonGap;
    int gradesButtonX = homeworkButtonX - homeworkButtonImg.width - buttonGap;

    int xOffsetLessons = xOffsetProg + progButtonImg.width + buttonGap - 260; // Right of physics button
    int yOffsetLesson1 = yOffset + progButtonImg.height + buttonGap + 180;
    int yOffsetLesson2 = yOffsetLesson1 + lesson1ButtonImg.height + lessonButtonGap;
    int yOffsetLesson3 = yOffsetLesson2 + lesson2ButtonImg.height + lessonButtonGap;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(progButtonImg, xOffsetProg, yOffset, WHITE);

        // Logical error: right now the homeworkTextButton is overlapping the gradesTextButton
        DrawTexture(courseButtonImg, courseButtonX, yOffset, WHITE);
        // DrawTexture(homeworkButtonImg, homeworkButtonX, yOffset, WHITE);
        DrawTexture(gradesButtonImg, gradesButtonX, yOffset, WHITE);

        DrawTexture(lesson1ButtonImg, xOffsetLessons, yOffsetLesson1, WHITE);
        DrawTexture(lesson2ButtonImg, xOffsetLessons, yOffsetLesson2, WHITE);

        DrawTexture(test1ButtonImg, xOffsetOthers - 1590, yOffsetLesson1 + 340, WHITE);
        DrawTexture(test2ButtonImg, xOffsetOthers - 1590, yOffsetLesson2 + 340, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetProg, (float)yOffset, (float)progButtonImg.width, (float)progButtonImg.height }) ||
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

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetProg, (float)yOffset, (float)progButtonImg.width, (float)progButtonImg.height })) {
            CloseWindow();
            progMenu();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson1, (float)lesson1ButtonImg.width, (float)lesson1ButtonImg.height })) {
            CloseWindow();
            //mathLesson1();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height })) {
            CloseWindow();
            // mathLesson2();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height })) {
            CloseWindow();
            // mathTest1();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
            CloseWindow();
            // mathTest2();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}