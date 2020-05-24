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

int floodfiller::floodfill(int curMap[MaxLen][MaxLen], int xi, int yi, int newVal)
{
	Queu *f = new_queu();
	return paint(curMap, xi, yi, newVal, f);
}

int floodfiller::floodfill(bool curMap[MaxLen][MaxLen], int xi, int yi, bool newVal)
{
	QueuB *f = new_queuB();
	return paint(curMap, xi, yi, newVal, f);
}

Queu * floodfiller::new_queu()
{
	return NULL;
}

QueuB * floodfiller::new_queuB()
{
	return NULL;
}

bool floodfiller::queu_empty(Queu * f)
{
	return (f == NULL);
}

bool floodfiller::queu_empty(QueuB * f)
{
	return (f == NULL);
}

Queu * floodfiller::push(Queu * f, int element)
{
	Queu *temp = f;
	Queu *neww = (Queu*)malloc(sizeof(Queu));
	neww->element = element;
	neww->next = NULL;
	if (queu_empty(f))
	{
		return neww;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = neww;
	return f;
}

QueuB * floodfiller::pushB(QueuB * f, int element)
{
	QueuB *temp = f;
	QueuB *neww = (QueuB*)malloc(sizeof(QueuB));
	neww->element = element;
	neww->next = NULL;
	if (queu_empty(f))
	{
		return neww;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = neww;
	return f;
}

Queu * floodfiller::pop(Queu * f)
{
	if (queu_empty(f))
	{
		return NULL;
	}
	Queu *temp = f->next;
	free(f);
	return temp;
}

QueuB * floodfiller::popB(QueuB * f)
{
	if (queu_empty(f))
	{
		return NULL;
	}
	QueuB *temp = f->next;
	free(f);
	return temp;
}

bool floodfiller::verify_start(int pos1, int pos2)
{
	return (pos1 >= 0 && pos1 < Width && pos2 >= 0 && pos2 < Height);
}

bool floodfiller::verify_position(int matrix[MaxLen][MaxLen], int pos1, int pos2, int firstPos)
{
	return (pos1 >= 0 && pos1 < Width && pos2 >= 0 && pos2 < Height) && matrix[pos1][pos2] == firstPos;
}

bool floodfiller::verify_position(bool matrix[MaxLen][MaxLen], int pos1, int pos2, bool firstPos)
{
	return (pos1 >= 0 && pos1 < Width && pos2 >= 0 && pos2 < Height) && matrix[pos1][pos2] == firstPos;
}

int floodfiller::paint(int matrix[MaxLen][MaxLen], int pos1, int pos2, int cor, Queu * f)
{
	int size = 0;

	int row[] = { -1,0,0,1 };
	int column[] = { 0,-1,1,0 };
	
	bool attempted[MaxLen][MaxLen];
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			attempted[x][y] = false;
		}
	}

	f = push(f, pos1);
	f = push(f, pos2);

	char firstPos = matrix[pos1][pos2];

	int i = 0;
	while (queu_empty(f) == false)
	{
		pos1 = f->element;
		f = pop(f);
		pos2 = f->element;
		f = pop(f);
		if (!attempted[pos1][pos2])//not done
		{
			matrix[pos1][pos2] = cor;
			size += 1;
			attempted[pos1][pos2] = true;
		}

		for (int x = 0; x < 4; x++)
		{
			if (verify_position(matrix, pos1 + row[x], pos2 + column[x], firstPos))
			{
				f = push(f, pos1 + row[x]);
				f = push(f, pos2 + column[x]);
			}
		}
		i += 1;
		if (i % callInt == 0)
			printStats(pos1, pos2, size);
	}
	return size;
}

int floodfiller::paint(bool matrix[MaxLen][MaxLen], int pos1, int pos2, bool cor, QueuB * f)
{
	int size = 0;

	int row[] = { -1,0,0,1 };
	int column[] = { 0,-1,1,0 };

	bool attempted[MaxLen][MaxLen];
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			attempted[x][y] = false;
		}
	}

	f = pushB(f, pos1);
	f = pushB(f, pos2);

	bool firstPos = matrix[pos1][pos2];

	int i = 0;
	while (queu_empty(f) == false)
	{
		pos1 = f->element;
		f = popB(f);
		pos2 = f->element;
		f = popB(f);
		if (!attempted[pos1][pos2])//not done
		{
			matrix[pos1][pos2] = cor;
			size += 1;
			attempted[pos1][pos2] = true;
		}

		for (int x = 0; x < 4; x++)
		{
			if (verify_position(matrix, pos1 + row[x], pos2 + column[x], firstPos))
			{
				f = pushB(f, pos1 + row[x]);
				f = pushB(f, pos2 + column[x]);
			}
		}
		i += 1;
		if (i % callInt == 0)
			printStats(pos1, pos2, size);
	}
	return size;
}

void floodfiller::printStats(int pos1, int pos2, int curSize)
{
	cout << "At point " << pos1 << ", " << pos2 << " CurSize=" << curSize << endl;
}
