#pragma once

#include "Position.h"

struct Bounds
{
	int x, y;
	int width, height;

	Bounds(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h)
	{
	}

	Position getTopLeft() const
	{ 
		return Position(x, y);
	}

	Position getBottomRight() const
	{
		return Position(x + width, y + height);
	}
};
