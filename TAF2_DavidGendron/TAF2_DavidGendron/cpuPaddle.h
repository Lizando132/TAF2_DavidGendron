#pragma once
#include "raylib.h"
#include "paddle.h"

class CpuPaddle : public Paddle
{
public:
	CpuPaddle(float startX, float startY, float w, float h, int spd, Color clr);

	void update(float ballY);
};