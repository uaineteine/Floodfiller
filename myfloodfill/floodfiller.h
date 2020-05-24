//	Uaine Teine 2020
//	Daniel Stamer-Squair
//	See licence info
#pragma once

#include "maplen.h"
#include <vector>

using namespace std;

typedef struct queu		//queu for next element with pointer
{						//
	int element;		//the element within the queu
	struct queu *next;	//
} Queu;

typedef struct queuB	//queu for next element with pointer
{						//
	int element;		//the element within the queu (boolean instead)
	struct queuB *next;	//
} QueuB;

class floodfiller
{
public:
//CONSTRUCTORS
	floodfiller(int w, int h);
	~floodfiller();
//FIELDS
	//Methods
	//Functions
	int floodfill(int curMap[MaxLen][MaxLen], int xi, int yi, int newVal);		//return the size of the region
	int floodfill(bool curMap[MaxLen][MaxLen], int xi, int yi, bool newVal);	//return the size of the region for boolean maps instead
	bool verify_start(int pos1, int pos2);
protected:
	//FIELDS
	int Width;
	int Height;
	//FUNTIONS
	Queu *new_queu();
	QueuB *new_queuB();
	bool queu_empty(Queu *f);
	bool queu_empty(QueuB *f);
	Queu *push(Queu *f, int element);
	QueuB *pushB(QueuB *f, int element);
	Queu* pop(Queu* f);
	QueuB* popB(QueuB* f);
	//tell me we are in the good region for those inputs
	bool verify_position(int matrix[MaxLen][MaxLen], int pos1, int pos2, int firstPos);
	bool verify_position(bool matrix[MaxLen][MaxLen], int pos1, int pos2, bool firstPos);
	int paint(int matrix[MaxLen][MaxLen], int pos1, int pos2, int cor, Queu *f);		//paint size returned 
	int paint(bool matrix[MaxLen][MaxLen], int pos1, int pos2, bool cor, QueuB *f);		//paint size returned for boolean maps
	void printStats(int pos1, int pos2, int curSize);
private:
	int callInt = 5000; //cals before print
};

