#include "Ball.h"
#include "Graphics.h"

void Ball::Update()
{
	x += vx;
	y += vy;

	const int left = x;
	const int right = x + 3;
	if (left < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x =  Graphics::ScreenWidth - 4;
		vx = -vx;
	}

	const int top = y;
	const int bottom = y + 3;
	if (top < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 4;
		vy = -vy;
	}
}

