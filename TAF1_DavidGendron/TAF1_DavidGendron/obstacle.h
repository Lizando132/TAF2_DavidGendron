#pragma once
#include "raylib.h"

class FallingObstacle
{
public:
	float x, y;
	float radius;
	Texture2D texture;

	FallingObstacle(float startX, float startY, float r, Texture2D tex);

	void fall();

	void draw();
};