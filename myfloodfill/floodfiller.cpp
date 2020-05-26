#include "floodfiller.h"
#include <iostream>

using namespace std;

floodfiller::floodfiller(int w, int h)
{
	Width = w;
	Height = h;
}

floodfiller::~floodfiller()
{
}

int floodfiller::floodfill(int ** curMap, int xi, int yi, int newVal)
{
	int row[4] = { 0, -1, 1, 0 };
	int col[4] = { -1, 0, 0, 1 };
	wipeQeue();					//make sure it is nothing before we begin
	int k = 0;					//point in qeue
	int size = 0;				//cursize
	int x = 0;					//new points declared here to be faster than finding new addresses in the loop
	int y = 0;					//same as above
	int x0 = 0;					//same
	int y0 = 0;					//same
	int orgVal = curMap[xi][yi];//original value
	addToQeue(coord(xi, yi));	//initialise the qeue for filling

	//map to check if something has been added to the qeue before or not
	bool** QeuedMap = dynInitaliser::makeBool(Width, Height, false);
	//paint original
	curMap[xi][yi] = newVal;
	QeuedMap[xi][yi] = true;
	size += 1;

	while (k < qeuelen)
	{
		x0 = qeue[k].x;		//start by getting my main point
		y0 = qeue[k].y;		//same here
		for (int j = 0; j < 4; j++)
		{
			x = x0 + col[j];
			y = y0 + row[j];
			if (boundchecker::inBounds(x, y, Width, Height))
			{
				//now to trial
				if (curMap[x][y] == orgVal)//can paint
				{
					if (!QeuedMap[x][y])
					{
						paintAndAddToQue(curMap, x, y, newVal);
						size += 1;
						QeuedMap[x][y] = true;
					}
				}
			}
		}
		//now that I am done with k
		k += 1;
	}
	dynInitaliser::del(QeuedMap, Width);		//wipe qeue map
	wipeQeue();									//make sure it goes back to nothing now that we are done
	return size;
}

void floodfiller::printStats(int pos1, int pos2, int curSize)
{
	cout << "At point " << pos1 << ", " << pos2 << " CurSize=" << curSize << endl;
}

void floodfiller::addToQeue(coord point)
{
	qeue.push_back(point);
	qeuelen += 1;
}

void floodfiller::wipeQeue()
{
	qeue = vector<coord>();
	qeuelen = 0;
}

void floodfiller::paintAndAddToQue(int ** curMap, int x, int y, int newVal)
{
	curMap[x][y] = newVal; //paint
	addToQeue(coord(x, y));//add
}

void floodfiller::removeFromQeue(int indexToRemove)
{

}
