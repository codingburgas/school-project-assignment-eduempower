#include "mathMenu.h"

void mathMenu() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");
	SetTargetFPS(30);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(DARKGREEN);
		EndDrawing();
	}

	CloseWindow();
}