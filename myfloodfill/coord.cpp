#include "coord.h"

coord::coord()
{
	x = 0;
	y = 0;
}

coord::coord(int xi, int yi)
{
	x = xi;
	y = yi;
}

coord::~coord()
{
}

bool coord::inMaxBounds()
{
	return boundchecker::inBounds(x, y, MaxLen, MaxLen);
}

float coord::calcDist(coord b)
{
	coord a = *this;
	if (a == b)//same points
		return 0;
	b = a - b; //overwrite to save on memory
	return b.mag();
}

float coord::mag()
{
	return sqrt(x * x + y * y);
}
