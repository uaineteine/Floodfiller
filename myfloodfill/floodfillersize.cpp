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
	dynInitaliser::del(tmpMap, Width); //cleaning up
	return floodfill(tmpMap, xi, yi, dummyVal);
}

void floodfillersize::getSizeArray(int ** curMap, int ** sizeArr, int lenx, int leny)
{
	//TODO
}
