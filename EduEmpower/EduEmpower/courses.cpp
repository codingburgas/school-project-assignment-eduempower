#include "courses.h"

void Courses() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");
	SetTargetFPS(30);

	Texture2D background = LoadTexture("../resources/background_courses.png");

	Texture2D physicsButton = LoadTexture("../resources/physics_button.png");
	Texture2D mathsButton = LoadTexture("../resources/maths_button.png");
	Texture2D programmingButton = LoadTexture("../resources/physics_button.png");

	Texture2D examsText = LoadTexture("../resources/exams_text.png");
	Texture2D gradesText = LoadTexture("../resources/grades_text.png");
	Texture2D exitText = LoadTexture("../resources/exit_text.png");

	const int buttonWidth = 272;
	const int buttonHeight = 370;
	const int buttonSpacing = 200;

	int yOffset = 80;
	int xOffset = 1150;
	int buttonGap = 120;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, WHITE);

		DrawTexture(physicsButton, (screenWidth - buttonWidth) / 2 - buttonWidth - buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);
		DrawTexture(mathsButton, (screenWidth - buttonWidth) / 2, (screenHeight - buttonHeight) / 2 + 140, WHITE);
		DrawTexture(programmingButton, (screenWidth - buttonWidth) / 2 + buttonWidth + buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);

		DrawTexture(examsText, xOffset, yOffset, WHITE);
		DrawTexture(gradesText, xOffset + examsText.width + buttonGap, yOffset, WHITE);
		DrawTexture(exitText, xOffset + examsText.width + buttonGap + gradesText.width + buttonGap, yOffset, WHITE);

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadTexture(physicsButton);
	UnloadTexture(mathsButton);
	UnloadTexture(programmingButton);
	UnloadTexture(examsText);
	UnloadTexture(gradesText);
	UnloadTexture(exitText);
}