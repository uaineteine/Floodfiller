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
	//get these values only without painting the lists
	int getSize(int** curMap, int xi, int yi);
	int getSize(bool** curMap, int xi, int yi);
	void getSizeArray(int** curMap, int** sizeArr, int lenx, int leny); //return size array
	void getSizeArray(bool** curMap, int** sizeArr, int lenx, int leny); //return size array
};

