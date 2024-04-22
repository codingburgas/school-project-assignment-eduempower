#include "physicsTest1.h"
#include "physicsMenu.h"
#include "Question.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <random>
#include "raylib.h"

// Function to display a question along with its possible answers vertically
void displayQuestion(const Question& question, int x, int y, int fontSize) {
    DrawText(question.question.c_str(), x, y, fontSize, WHITE);
    y += 50; // Increase vertical position for answers
    for (size_t i = 0; i < question.answers.size(); ++i) {
        DrawText(question.answers[i].c_str(), x + 50, y + i * 50, fontSize, WHITE); // Moved text to the right by 50 pixels
    }
}

// Function to display radio buttons for selecting answers
void displayRadioButtons(int x, int y, int selectedAnswer, int questionNumber, int fontSize, bool clickable, int* selectedAnswers) {
    y += 50; // Increase vertical position for radio buttons
    for (size_t i = 0; i < 3; ++i) {
        // Draw radio button
        Rectangle radioBtnRect = { x, y + i * 50, 20, 20 };
        DrawRectangleLinesEx(radioBtnRect, 2, WHITE);

        // Check if the radio button is clickable and if the mouse is over it
        if (clickable && CheckCollisionPointRec(GetMousePosition(), radioBtnRect)) {
            DrawRectangle(radioBtnRect.x, radioBtnRect.y, radioBtnRect.width, radioBtnRect.height, Fade(LIGHTGRAY, 0.5f)); // Highlight when hovered
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                selectedAnswers[questionNumber] = i; // Set the selected answer for the current question
            }
        }

        // If current option is selected, draw a checkmark
        if (i == selectedAnswers[questionNumber]) {
            DrawText("X", x + 5, y + i * 50 + 5, fontSize, WHITE);
        }

        // Display answer options using snprintf
        char answerOption[32]; // Allocate a buffer for the formatted answer option
        snprintf(answerOption, sizeof(answerOption), "%d. ", static_cast<int>(i) + 1);
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

    // Adding more questions
    Question q1;
    q1.question = "Which aspect of a quadratic inequality indicates the vertical stretch or compression of the parabola?";
    q1.answers = { "Coefficient \"a\"", "Coefficient \"b\"", "Coefficient \"c\"" };
    allQuestions.push_back(q1);

    Question q2;
    q2.question = "How do quadratic inequalities involving absolute values differ from standard quadratic inequalities?";
    q2.answers = { "They have two separate parabolas", "They always have complex solutions", "They involve additional restrictions on the variable" };
    allQuestions.push_back(q2);

    Question q3;
    q3.question = "What does coefficient \"b\" do in a quadratic inequality?";
    q3.answers = { "Stretches the parabola", "Shifts horizontally", "Shifts vertically" };
    allQuestions.push_back(q3);

    Question q4;
    q4.question = "What does a positive coefficient \"a\" indicate about the parabola's opening direction in a quadratic inequality?";
    q4.answers = { "Downward", "Upward", "Horizontal" };
    allQuestions.push_back(q4);

    Question q5;
    q5.question = "What role does the discriminant play in a quadratic inequality?";
    q5.answers = { "Determines number of solutions", "Positions the vertex", "Widens the parabola" };
    allQuestions.push_back(q5);

    Question q6;
    q6.question = "What do shaded regions represent in the graphical solution of a quadratic inequality?";
    q6.answers = { "Non-solution intervals", "Solution intervals", "Intersection points" };
    allQuestions.push_back(q6);

    Question q7;
    q7.question = "What effect does the constant term \"c\" have on a quadratic inequality?";
    q7.answers = { "Shifts vertically", "Shifts horizontally", "Widens the parabola" };
    allQuestions.push_back(q7);

    Question q8;
    q8.question = "What does the midpoint formula contribute to solving quadratic inequalities?";
    q8.answers = { "Locates the x-coordinate of the vertex", "None of the above", "Determines the parabola's width" };
    allQuestions.push_back(q8);

    Question q9;
    q9.question = "Why is factoring a useful technique in solving quadratic inequalities algebraically?";
    q9.answers = { "Simplifies the inequality", "Determines the vertex", "Identifies solutions directly" };
    allQuestions.push_back(q9);

    Question q10;
    q10.question = "What purpose does the midpoint formula serve when solving quadratic inequalities?";
    q10.answers = { "It locates the x-coordinate of the vertex", "It helps identify solutions within intervals", "It determines the parabola's width" };
    allQuestions.push_back(q10);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(allQuestions.begin(), allQuestions.end(), g);

    // Declare an array to store selected answers for each question
    int selectedAnswers[10] = { -1 }; // Initialize selected answers to -1

    int buttonWidth = physicsButtonImg.width;
    int buttonHeight = physicsButtonImg.height;
    int buttonPadding = 20; // Padding from the top and right edges
    int buttonX = screenWidth - buttonWidth - buttonPadding - 30; // X-coordinate
    int buttonY = buttonPadding + 5; // Y-coordinate

    const int numQuestionsToDisplay = 4; // Display all questions
    const int x = 50;
    const int y = 100;
    const int columnSpacing = 400; // Space between columns

    Rectangle physicsButtonRect = { buttonX, buttonY, buttonWidth, buttonHeight };

    int currentQuestionIndex = 0; // Initialize index to the first question
    bool isButtonPressed = false; // Flag to track button press

    while (!WindowShouldClose()) {
        // Check for mouse hover and button press
        bool isHover = CheckCollisionPointRec(GetMousePosition(), physicsButtonRect);
        isButtonPressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        BeginDrawing();
        ClearBackground(BLACK);
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

        // Draw next question button
        DrawRectangle(buttonX + buttonWidth - 100, buttonY + 800, 100, 50, GREEN);
        DrawText("Next", buttonX + buttonWidth - 90, buttonY + 815, 20, BLACK);

        // Check if the next button is pressed
        if (CheckCollisionPointRec(GetMousePosition(), { static_cast<float>(buttonX + buttonWidth - 100), static_cast<float>(buttonY + 800), 100.0f, 50.0f }) && isButtonPressed && currentQuestionIndex < allQuestions.size() - 1) {
            currentQuestionIndex++;
            isButtonPressed = false; // Reset button press flag
        }

        // Display the current question and radio buttons
        int xPos = x;
        int yPos = y;
        displayQuestion(allQuestions[currentQuestionIndex], xPos, yPos, 30); // Increased font size to 30
        displayRadioButtons(xPos, yPos, selectedAnswers[currentQuestionIndex], currentQuestionIndex + 1, 20, true, selectedAnswers); // Changed font size to 20 and pass true for clickable

        // Display index of the current question
        DrawText(TextFormat("Question %d / %d", currentQuestionIndex + 1, allQuestions.size()), screenWidth - 200, screenHeight - 50, 20, WHITE);

        EndDrawing();
    }


    CloseWindow();

    UnloadTexture(background);;
    UnloadTexture(physicsButtonImg);
    UnloadTexture(hover_physicsButtonImg);
}