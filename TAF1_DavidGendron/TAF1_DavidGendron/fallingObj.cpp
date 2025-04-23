#include "fallingObj.h"

FallingObject::FallingObject(float startX, float startY, float r, Texture2D tex)
{
	x = startX;
	y = startY;
	texture = tex;
	radius = r;
}

void FallingObject::draw()
{
	DrawTexture(texture, x, y, WHITE);
}

void FallingObject::fall()
{
	y += 5;
}