#pragma once

static class dynInitaliser
{
public:
	static float** makeFloat(int width, int height, float init);
	static int** makeInt(int width, int height, int init);
	static bool** makeBool(int width, int height, bool init);
	//removal
	static void del(float** map, int width);
	static void del(int** map, int width);
	static void del(bool** map, int width);
};

