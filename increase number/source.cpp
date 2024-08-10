#include <iostream>
#include <cstring>
#include "raylib.h"

struct Button
{
	Rectangle rec;
	Color color;
};

void initBut(Button &bt, Rectangle rec, Color cl);
bool checkPress(Button bt, Vector2 mouse);

int main()
{
	Button bt;
	int count = 0;
	Vector2 mouse{-1, -1};
	Rectangle rec{0, 350, 800, 150};
	initBut(bt, rec, BLUE);
	Color temp = {255, 255, 100, 200};
	InitWindow(800, 500, "My first raylib");
	SetTargetFPS(60);
	while(WindowShouldClose() == false)
	{
		mouse = {-1, -1};
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			mouse = GetMousePosition();
		}
		if(checkPress(bt, mouse)) count++;
		BeginDrawing();
		ClearBackground(temp);
		DrawText(TextFormat("%d", count), 350, 150, 100, WHITE);
		DrawRectangleRec(bt.rec, bt.color);
		DrawText(TextFormat("Press here"), 250, 410, 50, RED);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

void initBut(Button &bt, Rectangle rec, Color cl)
{
	bt.rec = rec;
	bt.color = cl;
}

bool checkPress(Button bt, Vector2 mouse)
{
	return(CheckCollisionPointRec(mouse, bt.rec));
}