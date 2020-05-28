#include "floodfillersize.h"
#include <algorithm>
#include <iostream>

using namespace std;

floodfillersize::~floodfillersize()
{
}

int floodfillersize::getSize(int ** curMap, int xi, int yi)
{
	int** tmpMap = dynInitaliser::duplicateInt(curMap, Width, Height);
	int dummyVal = curMap[xi][yi] + 1; //different value
	//finished
	int size = floodfill(tmpMap, xi, yi, dummyVal);
	dynInitaliser::del(tmpMap, Width); //cleaning up
	return size;
}

void floodfillersize::getSizeArray(int ** curMap, int ** sizeArr, int lenx, int leny)
{
	for (int x = 0; x < lenx; x++)
	{
		for (int y = 0; y < leny; y++)
		{
			sizeArr[x][y] = getSize(curMap, x, y);
		}
	}
	//returning sizeArr
}
