#pragma once

#include "boundchecker.h"
#include "maplen.h"
#include <math.h>       /* sqrt */

class coord
{
public:
	coord();//default to 0 0
	coord(int xi, int yi);
	~coord();
	int x;
	int y;
	bool inMaxBounds();

	//operator for equal positions
	bool operator==(const coord& other) const
	{
		if (other.x == x && other.y == y)
			return true;
		else
			return false;
	}

	coord operator+(const coord& other) const
	{
		coord out = other;
		out.x += x;
		out.y += y;
		return out;
	}

	coord operator-(const coord& other) const
	{
		coord out = coord(x, y);
		out.x -= other.x;
		out.y -= other.y;
		return out;
	}

	//CALC SOME VALUES
	float calcDist(coord b); //get distance between points using pythag
	float mag();
};