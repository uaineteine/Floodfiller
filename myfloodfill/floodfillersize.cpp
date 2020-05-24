#include "floodfillersize.h"
#include <algorithm>
#include <iostream>

using namespace std;

floodfillersize::~floodfillersize()
{
}

int floodfillersize::getSize(int map[MaxLen][MaxLen], int xi, int yi, int dummyVal)
{
	int tmpMap[MaxLen][MaxLen];
	copy(&map[0][0], &map[0][0] + MaxLen * MaxLen, &tmpMap[0][0]);
	return floodfill(tmpMap, xi, yi, dummyVal);
}

int floodfillersize::getSize(bool map[MaxLen][MaxLen], int xi, int yi, bool dummyVal)
{
	bool tmpMap[MaxLen][MaxLen];
	copy(&map[0][0], &map[0][0] + MaxLen * MaxLen, &tmpMap[0][0]);
	return floodfill(tmpMap, xi, yi, dummyVal);
}

int ** floodfillersize::getSizeArr(int map[MaxLen][MaxLen])
{
	int** array2D = 0;						//give 0 value for now
	array2D = new int*[MaxLen];				//x vals
	for (int x = 0; x < MaxLen; x++)
	{
		array2D[x] = new int[MaxLen];		//y vals
		for (int y = 0; y < MaxLen; y++)
		{
			if (x < Width && y < Height)
			{
				int dummyval = map[x][y] + 1;	//not the same value
				array2D[x][y] = getSize(map, x, y, dummyval);
			}
			else
			array2D[x][y] = -1;				//initial val of 'unused space'
		}
	}
	return array2D;							//return double pointer
}

int ** floodfillersize::getSizeArr(bool map[MaxLen][MaxLen])
{
	int** array2D = 0;						//give 0 value for now
	array2D = new int*[MaxLen];				//x vals
	for (int x = 0; x < MaxLen; x++)
	{
		array2D[x] = new int[MaxLen];		//y vals
		for (int y = 0; y < MaxLen; y++)
		{
			if (x < Width && y < Height)
			{
				int dummy = !map[x][y];
				array2D[x][y] = getSize(map, x, y, dummy);
			}
			else
				array2D[x][y] = -1;		//initial val of 'unused space'
		}
	}
	return array2D;							//return double pointer
}

int ** floodfillersize::getSizeArr(bool ** map)
{
	int tmpMap[MaxLen][MaxLen];
	for (int x = 0; x < MaxLen; x++)
	{
		for (int y = 0; y < MaxLen; y++)
		{
			tmpMap[x][y] = map[x][y];
		}
	}
	return getSizeArr(tmpMap);
}
