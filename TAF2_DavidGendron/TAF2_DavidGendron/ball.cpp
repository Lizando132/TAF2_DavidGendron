#include "raylib.h"
#include "ball.h"

Ball::Ball()
{
	x = 640;
	y = 400;
	speedX = 5;
	speedY = 5;
	radius = 20;
	color = YELLOW;
}

int Ball::getX() 
{
	return x;
}
int Ball::getY() 
{
	return y;
}

int Ball::getRadius() 
{
	return radius;
}

int Ball::getSpeedX() 
{
	return speedX;
}
int Ball::getSpeedY() 
{
	return speedY;
}

void Ball::setPosition(float newX, float newY) 
{
	newX = x;
	newY = y;
}
void Ball::setSpeed(int newSpeedX, int newSpeedY)
{
	newSpeedX = x;
	newSpeedY = y;
}

void Ball::CheckCollisionWithPaddle(Paddle paddle)
{
	Rectangle rec = { paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight() };
	
	if (CheckCollisionCircleRec(Vector2{ x, y }, radius, rec) == true)
	{
		speedX *= -1;
	}
}

void Ball::update()
{
	x += speedX;
	y += speedY;
	
	if ((y - radius <= 0) || (y + radius >= GetScreenHeight()))
	{
		speedY *= -1;  
	}
	if ((x - radius <= 0) || (x + radius >= GetScreenWidth()))
	{
		speedX *= -1; 
	}

}
void Ball::draw()
{
	DrawCircle(x, y, radius, YELLOW);
}

void Ball::reset()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;
	
	int directions[] = { -1, 1 };
	speedX *= directions[GetRandomValue(0, 1)];
	speedY *= directions[GetRandomValue(0, 1)];
}