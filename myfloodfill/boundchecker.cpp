#include "boundchecker.h"

bool boundchecker::inBounds(int x, int y, int w, int h)
{
	if (x < w && y < h)//in bounds
		if (x > -1 && y > -1)
			return true;
		else
			return false;
	else 
		return false;
}
