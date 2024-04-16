#include "courses.h"

void courses() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");
	SetTargetFPS(30);

	Texture2D background = LoadTexture("../resources/background_courses.png");

	Texture2D physicsButton = LoadTexture("../resources/physics_button.png");
	Texture2D mathsButton = LoadTexture("../resources/physics_button.png");
	Texture2D programmingButton = LoadTexture("../resources/physics_button.png");

	const int buttonWidth = 272;
	const int buttonHeight = 370;
	const int buttonSpacing = 200;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, WHITE);

		DrawTexture(physicsButton, (screenWidth - buttonWidth) / 2 - buttonWidth - buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);
		DrawTexture(mathsButton, (screenWidth - buttonWidth) / 2, (screenHeight - buttonHeight) / 2 + 140, WHITE);
		DrawTexture(programmingButton, (screenWidth - buttonWidth) / 2 + buttonWidth + buttonSpacing, (screenHeight - buttonHeight) / 2, WHITE);

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadTexture(physicsButton);
	UnloadTexture(mathsButton);
	UnloadTexture(programmingButton);
}