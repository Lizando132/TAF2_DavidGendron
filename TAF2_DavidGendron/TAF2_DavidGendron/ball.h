#pragma once
#include "raylib.h"
#include "paddle.h"


class Ball
{
private:
	float x, y;
	int speedX, speedY;
	int radius;
	Color color;

public:

	Ball();

	int getX();

	int getY();


	int getRadius();


	int getSpeedX();

	int getSpeedY();


	virtual void setPosition(float newX, float newY);

	virtual void setSpeed(int newSpeedX, int newSpeedY);
	

	void CheckCollisionWithPaddle(Paddle paddle);

	void draw();

	void update();

	void reset();
};