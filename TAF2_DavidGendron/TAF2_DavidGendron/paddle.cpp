#include "raylib.h"
#include "paddle.h"

Paddle::Paddle(float startX, float startY, float w, float h, int spd, Color clr)
{
	this->x = startX;
	this->y = startY;
	this->width = w;
	this->height = h;
	this->speed = spd;
	this->color = clr;
}

int Paddle::getX() 
{
	return x;
}
int Paddle::getY() 
{
	return y;
}

int Paddle::getWidth() 
{
	return width;
}
int Paddle::getHeight() 
{
	return height;
}

int Paddle::getSpeed() 
{
	return speed;
}

void Paddle::setPosition(float newX, float newY) 
{
	x = newX;
	y = newY;
}
void Paddle::setSpeed(int newSpeed) 
{
	speed = newSpeed;
}

void Paddle::limitMovement()
{
	if (y + height >= GetScreenHeight()) 
	{
		y = (float)GetScreenHeight() - height;
	}

	if (y <= 0) 
	{
		y = 0;
	}
}

void Paddle::draw() 
{
	DrawRectangle(x, y, width, height, color);
}

void Paddle::update()
{
	if (IsKeyDown(KEY_UP)) y -= speed;
	if (IsKeyDown(KEY_DOWN)) y += speed;
	limitMovement();
}