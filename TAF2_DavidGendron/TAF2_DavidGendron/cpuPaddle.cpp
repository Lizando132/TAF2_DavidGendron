#include "raylib.h"
#include "cpuPaddle.h"
#include "paddle.h"

CpuPaddle::CpuPaddle(float startX, float startY, float w, float h, int spd, Color clr)
	: Paddle(startX, startY, w, h, spd, clr)
{
	
}

void CpuPaddle::update(float ballY) 
{
	if (getY() + height / 2 > ballY) 
	{
		y -= speed;
	}
	else if (getY() + height / 2 < ballY) 
	{  
		y += speed;
	}
	limitMovement();
}

