#include "physicsTest1.h"
#include "physicsMenu.h"
#include "Question.h"
#include <iostream>
#include <cstdio>

// Function to display a question along with its possible answers vertically
void displayQuestion(const Question& question, int x, int y, int fontSize) {
    DrawText(question.question.c_str(), x, y, fontSize, WHITE);
    y += 50; // Increase vertical position for answers
    for (size_t i = 0; i < question.answers.size(); ++i) {
        DrawText(question.answers[i].c_str(), x + 50, y + i * 50, fontSize, WHITE); // Moved text to the right by 50 pixels
    }
}

// Function to display radio buttons for selecting answers
void displayRadioButtons(int x, int y, int selectedAnswer, int questionNumber, int fontSize, bool clickable, int& clickedAnswer) {
    y += 50; // Increase vertical position for radio buttons
    for (size_t i = 0; i < 3; ++i) {
        // Draw radio button
        Rectangle radioBtnRect = { x, y + i * 50, 20, 20 };
        DrawRectangleLinesEx(radioBtnRect, 2, WHITE);

        // Check if the radio button is clickable and if the mouse is over it
        if (clickable && CheckCollisionPointRec(GetMousePosition(), radioBtnRect)) {
            DrawRectangle(radioBtnRect.x, radioBtnRect.y, radioBtnRect.width, radioBtnRect.height, Fade(LIGHTGRAY, 0.5f)); // Highlight when hovered
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                clickedAnswer = i; // Set the clicked answer
            }
        }

        // If current option is selected, draw a checkmark
        if (i == selectedAnswer) {
            DrawText("X", x + 5, y + i * 50 + 5, fontSize, WHITE);
        }

        // Display answer options using snprintf
        char answerOption[32]; // Allocate a buffer for the formatted answer option
        snprintf(answerOption, sizeof(answerOption), "%d. ", i + 1);
        DrawText(answerOption, x + 30, y + i * 50, fontSize, WHITE);
    }
}

void physicsTest1() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/test1_physics.png");
    Texture2D physicsButtonImg = LoadTexture("../resources/Physics_yellow.png");
    Texture2D hover_physicsButtonImg = LoadTexture("../resources/Physics_white.png");

    std::vector<Question> allQuestions;

    Question q1;
    q1.question = "What is the capital of France?";
    q1.answers = { "Paris", "London", "Berlin" };
    allQuestions.push_back(q1);

    Question q2;
    q2.question = "What is the largest planet in our solar system?";
    q2.answers = { "Jupiter", "Mars", "Saturn" };
    allQuestions.push_back(q2);

    int selectedAnswers[2] = { -1 }; // Initialize selected answers to -1
    int currentQuestionIndex = 0;
    int clickedAnswer = -1; // Store the clicked answer

    int buttonWidth = physicsButtonImg.width;
    int buttonHeight = physicsButtonImg.height;
    int buttonPadding = 20; // Padding from the top and right edges
    int buttonX = screenWidth - buttonWidth - buttonPadding - 30; // X-coordinate
    int buttonY = buttonPadding + 5; // Y-coordinate

    const int numQuestionsToDisplay = 2; // Display only 2 questions for testing purpose
    const int x = 50;
    const int y = 100;

    Rectangle physicsButtonRect = { buttonX, buttonY, buttonWidth, buttonHeight };

    while (!WindowShouldClose()) {
        // Check for mouse hover
        bool isHover = CheckCollisionPointRec(GetMousePosition(), physicsButtonRect);

        BeginDrawing();
        ClearBackground(BLACK); // Changed background color to BLACK

        // Draw background
        DrawTexture(background, 0, 0, WHITE);

        // Draw physics button
        if (isHover) {
            // Change cursor to pointer
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

            // Change image on hover
            DrawTexture(hover_physicsButtonImg, buttonX, buttonY, WHITE);
        }
        else {
            // Reset cursor to default
            SetMouseCursor(MOUSE_CURSOR_ARROW);

            // Draw default button image
            DrawTexture(physicsButtonImg, buttonX, buttonY, WHITE);
        }

        for (int currentQuestionIndex = 0; currentQuestionIndex < numQuestionsToDisplay; currentQuestionIndex++) {
            // Adjust horizontal position for each question
            int xPos = x + currentQuestionIndex * 800; // Change 800 to desired spacing
            displayQuestion(allQuestions[currentQuestionIndex], xPos, y, 30); // Increased font size to 30
            displayRadioButtons(xPos, y, selectedAnswers[currentQuestionIndex], currentQuestionIndex + 1, 20, true, clickedAnswer); // Changed font size to 20 and pass true for clickable
        }

        EndDrawing();
    }

    CloseWindow();

    UnloadTexture(background);
    UnloadTexture(physicsButtonImg);
}
