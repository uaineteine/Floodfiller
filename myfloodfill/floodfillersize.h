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
};

