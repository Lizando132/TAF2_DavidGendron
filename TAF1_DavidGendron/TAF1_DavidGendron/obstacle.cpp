#include "obstacle.h"

FallingObstacle::FallingObstacle(float startX, float startY, float r, Texture2D tex)
{
	x = startX;
	y = startY;
	texture = tex;
	radius = r;

}

void FallingObstacle::fall()
{
	y += 6;
}

void FallingObstacle::draw()
{
	DrawTexture(texture, x, y, WHITE);
}