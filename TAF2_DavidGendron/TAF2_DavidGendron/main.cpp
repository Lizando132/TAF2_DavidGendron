#include "raylib.h"
#include "ball.h"
#include "cpuPaddle.h"
#include "Paddle.h"


Color Green = Color{ 38, 185, 154, 255 };
Color Dark_Green = Color{ 20, 160, 133, 255 };
Color Light_Green = Color{ 129, 204, 184, 255 };
Color Yellow = Color{ 243, 213, 91, 255 };

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Pong!");
	SetTargetFPS(60);

	int playerScore = 0;
	int cpuScore = 0;
	float elapsedTime = 0.0f;
	float maxTime = 180.0f;
	bool isGameOver = false;

	Ball ball;
	Paddle player(1230, 400, 20, 100, 10, WHITE);
	CpuPaddle cpu(50, 400, 20, 100, 10, WHITE);


	while (!WindowShouldClose())
	{
		ball.update();
		{
			ball.CheckCollisionWithPaddle(player);
			ball.CheckCollisionWithPaddle(cpu);

			if ((ball.getX() + ball.getRadius() >= GetScreenWidth()))
			{
				cpuScore++;
				ball.reset();
			}
			if ((ball.getX() + ball.getRadius() <= 0))
			{
				playerScore++;
				ball.reset();
			}
		}
		player.update();
		cpu.update(ball.getY());
	

		elapsedTime += GetFrameTime();

		if (elapsedTime >= 5.0f) {
			
			ball.setSpeed(ball.getSpeedX() * 1.5, ball.getSpeedY() * 1.5);

			player.setSpeed(player.getSpeed() + 0.5);
			
		}
		
		BeginDrawing();

		ClearBackground(Dark_Green);
		DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
		DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

		ball.draw();
		player.draw();
		cpu.draw();

		DrawText(TextFormat("%d", playerScore), screenWidth / 2 + 50, 20, 40, WHITE);
		DrawText(TextFormat("%d", cpuScore), screenWidth / 2 - 100, 20, 40, WHITE);

		if (isGameOver == false)
		{
			float remainingTime = maxTime - elapsedTime;

			if (remainingTime <= 0)
			{
				remainingTime = 0;
				isGameOver = true;
			}
			DrawText(TextFormat("Time: %.0f sec", remainingTime), 20, 20, 30, WHITE);
		}
		else
		{
			ClearBackground(Dark_Green);
			DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
			DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

			DrawText("GAME OVER", screenWidth / 2 - 120, screenHeight / 2 - 70, 40, RED);

			DrawText(TextFormat("Player Score: %d", playerScore), screenWidth / 2 - 120, screenHeight / 2 - 20, 30, WHITE);
			DrawText(TextFormat("CPU Score: %d", cpuScore), screenWidth / 2 - 120, screenHeight / 2 + 10, 30, WHITE);

			if (playerScore > cpuScore)
			{
				DrawText("YOU WIN!", screenWidth / 2 - 100, screenHeight / 2 + 50, 40, GREEN);
			}
			else if (cpuScore > playerScore)
			{
				DrawText("CPU WIN!", screenWidth / 2 - 100, screenHeight / 2 + 50, 40, GREEN);
			}
			else
			{
				DrawText("DRAW!", screenWidth / 2 - 55, screenHeight / 2 + 50, 40, GREEN);
			}

			DrawText("Press [ESC] to Quit", screenWidth / 2 - 100, screenHeight / 2 + 150, 20, WHITE);

		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}