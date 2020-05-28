#include "dynInitaliser.h"

float ** dynInitaliser::makeFloat(int width, int height, float init)
{
	float** h = 0;							//give 0 value for now
	h = new float*[width];					//x vals
	for (int x = 0; x < width; x++)
	{
		h[x] = new float[height];				//y vals
		for (int y = 0; y < height; y++)
		{
			h[x][y] = init;
		}
	}
	return h;
}

int ** dynInitaliser::makeInt(int width, int height, int init)
{
	int** h = 0;							//give 0 value for now
	h = new int*[width];					//x vals
	for (int x = 0; x < width; x++)
	{
		h[x] = new int[height];				//y vals
		for (int y = 0; y < height; y++)
		{
			h[x][y] = init;
		}
	}
	return h;
}

bool ** dynInitaliser::makeBool(int width, int height, bool init)
{
	bool** h = 0;							//give 0 value for now
	h = new bool*[width];					//x vals
	for (int x = 0; x < width; x++)
	{
		h[x] = new bool[height];				//y vals
		for (int y = 0; y < height; y++)
		{
			h[x][y] = init;
		}
	}
	return h;
}

void dynInitaliser::del(float ** map, int width)
{
	for (int i = 0; i < width; i++)
		delete[] map[i];

	delete[] map;
}

void dynInitaliser::del(int ** map, int width)
{
	for (int i = 0; i < width; i++)
		delete[] map[i];

	delete[] map;
}

void dynInitaliser::del(bool ** map, int width)
{
	for (int i = 0; i < width; i++)
		delete[] map[i];

	delete[] map;
}

int ** dynInitaliser::duplicateInt(int ** CurMap, int width, int height)
{
	int ** newMap = makeInt(width, height, 0);
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			newMap[x][y] = CurMap[x][y];
		}
	}
	return newMap;
}
