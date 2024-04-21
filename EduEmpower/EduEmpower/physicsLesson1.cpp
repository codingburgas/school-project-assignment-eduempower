#include "physicsLesson1.h"


void physicsLesson1()
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "EduEmpoyer");
	SetTargetFPS(30);

	Texture2D background = LoadTexture("../resources/bg-physics-lesson-1.png");

	Texture2D physicsButtonImg = LoadTexture("../resources/Physics.png");
	Texture2D lesson1ButtonImg = LoadTexture("../resources/Lesson1.png");
	Texture2D lesson2ButtonImg = LoadTexture("../resources/Lesson2.png");

	Texture2D test1ButtonImg = LoadTexture("../resources/test1.png");
	Texture2D test2ButtonImg = LoadTexture("../resources/test2.png");

	Texture2D finalTestButtonImg = LoadTexture("../resources/finalTest.png");

	Texture2D courseButtonImg = LoadTexture("../resources/Course.png");

	int yOffset = 60;
	int xOffsetPhysics = 145; // Top left corner
	int xOffsetOthers = screenWidth - courseButtonImg.width - 50; // Top right corner
	int buttonGap = 20;
	int lessonButtonGap = 40; // Gap between lesson buttons

	int courseButtonX = screenWidth - courseButtonImg.width - 50;
	int homeworkButtonX = courseButtonX - courseButtonImg.width - buttonGap;

	int xOffsetLessons = xOffsetPhysics + physicsButtonImg.width + buttonGap - 230; // Right of physics button
	int yOffsetLesson1 = yOffset + physicsButtonImg.height + buttonGap + 150;
	int yOffsetLesson2 = yOffsetLesson1 + lesson1ButtonImg.height + lessonButtonGap;
	int yOffsetLesson3 = yOffsetLesson2 + lesson2ButtonImg.height + lessonButtonGap;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawTexture(background, 0, 0, WHITE);

		DrawTexture(physicsButtonImg, xOffsetPhysics, yOffset, WHITE);

		DrawTexture(lesson1ButtonImg, xOffsetLessons, yOffsetLesson1, WHITE);
		DrawTexture(lesson2ButtonImg, xOffsetLessons, yOffsetLesson2, WHITE);

		DrawTexture(test1ButtonImg, xOffsetOthers - 1590, yOffsetLesson1 + 340, WHITE);
		DrawTexture(test2ButtonImg, xOffsetOthers - 1590, yOffsetLesson2 + 340, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetPhysics, (float)yOffset, (float)physicsButtonImg.width, (float)physicsButtonImg.height }) ||
			CheckCollisionPointRec(GetMousePosition(), { (float)courseButtonX, (float)yOffset, (float)courseButtonImg.width, (float)courseButtonImg.height }) ||
			CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height }) ||
			CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height }) ||
			CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
		else {
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)xOffsetLessons, (float)yOffsetLesson2, (float)lesson2ButtonImg.width, (float)lesson2ButtonImg.height })) {
			CloseWindow();
			physicsLesson2();
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson1 + 340), (float)test1ButtonImg.width, (float)test1ButtonImg.height })) {
			CloseWindow();
			physicsTest1();
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), { (float)(xOffsetOthers - 1590), (float)(yOffsetLesson2 + 360), (float)test2ButtonImg.width, (float)test2ButtonImg.height })) {
			CloseWindow();
			physicsTest2();
		}
		EndDrawing();
	}
	UnloadTexture(background);
	UnloadTexture(courseButtonImg);
	UnloadTexture(physicsButtonImg);
	UnloadTexture(lesson1ButtonImg);
	UnloadTexture(lesson2ButtonImg);
	UnloadTexture(test1ButtonImg);
	UnloadTexture(test2ButtonImg);
	UnloadTexture(finalTestButtonImg);

	CloseWindow();
}