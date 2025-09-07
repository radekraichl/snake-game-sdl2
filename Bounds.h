#pragma once

#include "Position.h"

struct Bounds
{
	float x, y;
	float width, height;

	Bounds(float x = 0, float y = 0, float w = 0, float h = 0) : x(x), y(y), width(w), height(h)
	{
	}
};
