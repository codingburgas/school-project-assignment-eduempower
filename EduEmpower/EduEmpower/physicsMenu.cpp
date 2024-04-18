#include "physicsMenu.h"

int physicsMenu() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/background_physics_main_page.png");

    Texture2D courseTextButton = LoadTexture("../resources/Course.png");
    Texture2D homeworkTextButton = LoadTexture("../resources/Homework.png");
    Texture2D gradesTextButton = LoadTexture("../resources/grades_text.png");

    Texture2D physicsButton = LoadTexture("../resources/Physics.png");
    Texture2D lesson1Button = LoadTexture("../resources/Lesson1.png");
    Texture2D lesson2Button = LoadTexture("../resources/Lesson2.png");
    Texture2D lesson3Button = LoadTexture("../resources/Lesson3.png");

    Texture2D test1Button = LoadTexture("../resources/test1.png");
    Texture2D test2Button = LoadTexture("../resources/test2.png");

    Texture2D finalTestButton = LoadTexture("../resources/finalTest.png");

    int yOffset = 60;
    int xOffsetPhysics = 170; // Top left corner
    int xOffsetOthers = screenWidth - courseTextButton.width - 50; // Top right corner
    int buttonGap = 20;
    int lessonButtonGap = 30; // Gap between lesson buttons

    // Position of navigation buttons
    int courseButtonX = screenWidth - courseTextButton.width - 50;
    int homeworkButtonX = courseButtonX - courseTextButton.width - buttonGap;
    int gradesButtonX = homeworkButtonX - homeworkTextButton.width - buttonGap;

    int xOffsetLessons = xOffsetPhysics + physicsButton.width + buttonGap - 150; // Right of physics button
    int yOffsetLesson1 = yOffset + physicsButton.height + buttonGap + 150;
    int yOffsetLesson2 = yOffsetLesson1 + lesson1Button.height + lessonButtonGap;
    int yOffsetLesson3 = yOffsetLesson2 + lesson2Button.height + lessonButtonGap;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(physicsButton, xOffsetPhysics, yOffset, WHITE);

        // Logical error: right now the homeworkTextButton is overlapping the gradesTextButton
        DrawTexture(courseTextButton, courseButtonX, yOffset, WHITE);
        DrawTexture(homeworkTextButton, homeworkButtonX, yOffset, WHITE);
        DrawTexture(gradesTextButton, gradesButtonX, yOffset, WHITE);

        DrawTexture(lesson1Button, xOffsetLessons, yOffsetLesson1, WHITE);
        DrawTexture(lesson2Button, xOffsetLessons, yOffsetLesson2, WHITE);
        DrawTexture(lesson3Button, xOffsetLessons, yOffsetLesson3, WHITE);

        

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(courseTextButton);
    UnloadTexture(homeworkTextButton);
    UnloadTexture(gradesTextButton);
    UnloadTexture(physicsButton);
    UnloadTexture(lesson1Button);
    UnloadTexture(lesson2Button);
    UnloadTexture(lesson3Button);
    UnloadTexture(test1Button);
    UnloadTexture(test2Button);
    UnloadTexture(finalTestButton);

    CloseWindow();
    return 0;
}