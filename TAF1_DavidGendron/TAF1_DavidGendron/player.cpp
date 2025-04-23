#include "player.h"

Player::Player(float startX, float startY, float w, float h, Texture2D tex)
{
	x = startX;
	y = startY;
	texture = tex;
	width = texture.width;
	height = texture.height;
}

void Player::draw()
{
	DrawTexture(texture, x, y, WHITE);
}

void Player::move(int direction)
{
	x += direction * 10;
	if (x < 0) x = 0;
	if (x + width > 800) x = 800 - width;
}