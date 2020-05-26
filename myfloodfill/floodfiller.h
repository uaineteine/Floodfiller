//	Uaine Teine 2020
//	Daniel Stamer-Squair
//	See licence info
#pragma once

#include "maplen.h"
#include "coord.h"
#include "boundchecker.h"
#include "dynInitaliser.h"
#include <vector>

using namespace std;

class floodfiller
{
public:
//CONSTRUCTORS
	floodfiller(int w, int h);
	~floodfiller();
//Functions
	int floodfill(int **curMap, int xi, int yi, int newVal);		//return the size of the region
protected:
	//FIELDS
	int Width;
	int Height;
	void printStats(int pos1, int pos2, int curSize);
	vector<coord> qeue;
	void addToQeue(coord point);
	void wipeQeue();
	void paintAndAddToQue(int** curMap, int x, int y, int newVal);
	void removeFromQeue(int indexToRemove);
	int qeuelen = 0;
private:
	int callInt = 5000; //cals before print
};

