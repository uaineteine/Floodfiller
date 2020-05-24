//	Uaine Teine 2020
//	Daniel Stamer-Squair
//	See licence info
#pragma once

#include "floodfiller.h"

class floodfillersize : public floodfiller
{
public:
	floodfillersize(int w, int h) : floodfiller(w, h) { };
	~floodfillersize();
	int getSize(int map[MaxLen][MaxLen], int xi, int yi, int dummyVal);
	int getSize(bool map[MaxLen][MaxLen], int xi, int yi, bool dummyVal);
	int** getSizeArr(int map[MaxLen][MaxLen]);	//get whole array of sizes of chamber
	int** getSizeArr(bool map[MaxLen][MaxLen]);//get whole array of sizes of chamber for booleans
	int** getSizeArr(bool** map);//get whole array of sizes of chamber for booleans //maxlen by maxlen
};

