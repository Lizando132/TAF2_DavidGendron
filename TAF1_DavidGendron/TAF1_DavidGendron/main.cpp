#include "raylib.h"
#include "player.h"
#include "fallingObj.h"
#include "obstacle.h"
#include <vector>


int main()
{
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Attrapez-les tous!");
	SetTargetFPS(60);
	Texture2D playerTexture = LoadTexture("player.png");

	Player player(350, 450, 100, 20, playerTexture);

	std::vector<FallingObject> objects;
	
	std::vector<FallingObstacle>obstacles;

	int frameCounter = 0;

	int score = 0;

	int lives = 10;

	Texture2D obstacleTexture = LoadTexture("obstacle.png");
	Texture2D objectTexture = LoadTexture("object.png");
	while (!WindowShouldClose() && lives > 0)
	{
		frameCounter++;
		if (frameCounter % 60 == 0)
		{
			int randomPositionX = rand() % screenWidth;
			FallingObject f = FallingObject(randomPositionX, 0, 20, objectTexture);
			objects.push_back(f);
		}
		if (frameCounter % 120 == 0)
		{
			int randomPositionX = rand() % screenWidth;
			FallingObstacle f = FallingObstacle(randomPositionX, 0, 20, obstacleTexture);
			obstacles.push_back(f);
		}

		for (int i = 0; i < objects.size(); i++)
		{
			objects[i].fall();
			if (objects[i].y - objects[i].radius > 600)
			{
				objects.erase(objects.begin() + i);
				i--;
				lives--;
			}
		}
		
		Vector2 objCenter;
		int objRadius;
		Rectangle rec = { player.x, player.y, player.width, player.height };
		for (int i = 0; i < objects.size(); i++)
		{
			objCenter = { objects[i].x, objects[i].y };
			objRadius = objects[i].radius;

			if (CheckCollisionCircleRec(objCenter, objRadius, rec) == true)
			{
				objects.erase(objects.begin() + i);
				score++;
				break;
			}
		}

		Vector2 obstaCenter;
		int obstaRadius;
		for (int i = 0; i < obstacles.size(); i++)
		{
			obstaCenter = { obstacles[i].x, obstacles[i].y };
			obstaRadius = obstacles[i].radius;
			if (CheckCollisionCircleRec(obstaCenter, obstaRadius, rec) == true)
			{
				obstacles.erase(obstacles.begin() + i);
				lives--;
				break;
			}
		}

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles[i].fall();
			if (obstacles[i].y - (obstacles[i].x && obstacles[i].y) > 600)
			{
				obstacles.erase(obstacles.begin() + i);
			}
		}

		if (IsKeyDown(KEY_LEFT)) player.move(-1);
		if (IsKeyDown(KEY_RIGHT)) player.move(1);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		player.draw();

		for (int i = 0; i < objects.size(); i++)
		{
			objects[i].draw();
		}

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles[i].draw();
		}

		DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
		DrawText(TextFormat("Lives: %d", lives), 710, 10, 20, RED);

		EndDrawing();
	}

	if (lives <= 0)
	{
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("GAME OVER", 260, 250, 40, RED);
			DrawText(TextFormat("Score final: %d", score), 320, 300, 20, RAYWHITE);
			DrawText("[Esc] pour quitter", 10, 10, 20, GRAY);

			EndDrawing();

			if (IsKeyPressed(KEY_ESCAPE)) break;
		}
	}

	CloseWindow();
	return 0;
}