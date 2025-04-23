#pragma once
#include "raylib.h"

class Player
{
public:
	float x, y;
	float width, height;

	Texture2D texture;

	Player(float startX, float startY, float w, float h, Texture2D tex);
	void draw();

	void move(int direction);
};