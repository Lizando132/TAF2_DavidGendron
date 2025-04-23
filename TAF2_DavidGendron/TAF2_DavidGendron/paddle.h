#pragma once
#include "raylib.h"

class Paddle
{
protected:
	float x, y;
	float width, height;
	int speed;
	Color color;

	void limitMovement();

public:
	Paddle(float startX, float startY, float w, float h, int spd, Color clr);

	int getX();
	
	int getY();
	

	int getWidth();
	
	int getHeight();
	

	int getSpeed();
	

	void setPosition(float newX, float newY);
	
	void setSpeed(int newSpeed);
	

	void draw();

	void update();
};