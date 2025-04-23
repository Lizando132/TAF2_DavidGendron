#pragma once
#include "raylib.h"

class FallingObject
{
public:
	float x, y;
	float radius;
	Texture2D texture;

	FallingObject(float startX, float startY, float r, Texture2D tex);
	void draw();

	void fall();
};
