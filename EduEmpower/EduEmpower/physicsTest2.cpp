#include "physicsTest2.h"

void physicsTest2() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");	
	SetTargetFPS(30);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Physics Test 1", 10, 10, 20, DARKGRAY);
		EndDrawing();
	}
	CloseWindow();
}