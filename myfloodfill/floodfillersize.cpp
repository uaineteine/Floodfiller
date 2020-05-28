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
	int size = floodfill(tmpMap, xi, yi, dummyVal);
	dynInitaliser::del(tmpMap, Width); //cleaning up
	return size;
}

int floodfillersize::getSize(bool ** curMap, int xi, int yi)
{
	bool** tmpMap = dynInitaliser::duplicateBool(curMap, Width, Height);
	bool dummyVal = true;
	if (tmpMap[xi][yi])//if true
		dummyVal = false;
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

void floodfillersize::getSizeArray(bool ** curMap, int ** sizeArr, int lenx, int leny)
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
