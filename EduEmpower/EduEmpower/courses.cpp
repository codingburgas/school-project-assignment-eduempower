#include "courses.h"

int Courses() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");
	SetTargetFPS(30);

	Texture2D background = LoadTexture("../resources/background_courses.png");

	Texture2D physicsButton = LoadTexture("../resources/physics_button.png");
	Texture2D mathsButton = LoadTexture("../resources/maths_button.png");
	Texture2D programmingButton = LoadTexture("../resources/programming_button.png");

	Texture2D examsText = LoadTexture("../resources/exams_text.png");
	Texture2D gradesText = LoadTexture("../resources/grades_text.png");
	Texture2D exitText = LoadTexture("../resources/exit_text.png");

	const int buttonWidth = 272;
	const int buttonHeight = 370;
	const int buttonSpacing = 200;

	int yOffset = 80; // 80 pixels from the top of the screen to the text buttons
	int xOffset = 1150; // 1150 pixels from the left of the screen to the text buttons
	int buttonGap = 120; // 120 pixels between each text button

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, WHITE);

		DrawTexture(physicsButton, (screenWidth - buttonWidth) / 2 - buttonWidth - buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);
		DrawTexture(mathsButton, (screenWidth - buttonWidth) / 2, (screenHeight - buttonHeight) / 2 + 140, WHITE);
		DrawTexture(programmingButton, (screenWidth - buttonWidth) / 2 + buttonWidth + buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2 - buttonWidth - buttonSpacing, (screenHeight - buttonHeight) / 2, buttonWidth, buttonHeight })) {
			CloseWindow();
			physicsMenu();
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2, (screenHeight - buttonHeight) / 2 + 140, buttonWidth, buttonHeight })) {
			CloseWindow();
			mathMenu();
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2 + buttonWidth + buttonSpacing, (screenHeight - buttonHeight) / 2, buttonWidth, buttonHeight })) {
			CloseWindow();
			progMenu();
		}

		if (CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2 - buttonWidth - buttonSpacing, (screenHeight - buttonHeight) / 2, buttonWidth, buttonHeight })) {
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2, (screenHeight - buttonHeight) / 2 + 140, buttonWidth, buttonHeight })) {
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), { (screenWidth - buttonWidth) / 2 + buttonWidth + buttonSpacing, (screenHeight - buttonHeight) / 2, buttonWidth, buttonHeight })) {
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
		else {
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}

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

	return 0;
}