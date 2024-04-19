#include "physicsTest1.h"

void physicsTest1() {
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpower");
	SetTargetFPS(30);

	while (!WindowShouldClose()){
		BeginDrawing();
		DrawText("Physics Test 2", 10, 10, 20, DARKGRAY);
		EndDrawing();
	}

	CloseWindow();
}