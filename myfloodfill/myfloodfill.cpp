// myfloodfill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <malloc.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "floodfiller.h"
#include "floodfillersize.h"
#include "dynInitaliser.h"

using namespace std;

/////////////
//FIELDS
/////////////

int Width = 10;
int Height = 10;

/////////////
//methods and functions
/////////////

void print_matrix(int matrix[MaxLen][MaxLen])
{
	cout << endl;
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void print_matrix(bool matrix[MaxLen][MaxLen])
{
	cout << endl;
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void print_matrix(bool** matrix)
{
	cout << endl;
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void print_matrix(int** matrix)
{
	cout << endl;
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int getFromBool(int i)
{
	if (i == 0)
		return false;
	else
		return true;
}

void intTest()
{
	std::cout << "Hello World!\n";
	ifstream fileMatrix;
	int pos1, pos2;
	int cor;
	floodfiller filler = floodfiller(Width, Height);
	int**matrix = dynInitaliser::makeInt(MaxLen, MaxLen, 0);

	fileMatrix.open("matrix.txt");
	if (!fileMatrix.is_open())
	{
		cout << "No file found!" << endl;
	}

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			fileMatrix >> matrix[i][j];
		}
	}

	print_matrix(matrix);

	cout << endl << "Type the coordinates you want to paint (Row and Column): ";
	cin >> pos1 >> pos2;
	cout << endl << "What color you want to paint with (char): ";
	cin >> cor;
	int size = filler.floodfill(matrix, pos1, pos2, cor);
	print_matrix(matrix);
	cout << endl;
	cout << "Chamber was " << size << " cells large" << endl;
	cout << endl;
}


void boolTest()
{
	srand(time(NULL));

	int pos1, pos2;
	int cor;
	floodfiller filler = floodfiller(Width, Height);
	bool** matrix = dynInitaliser::makeBool(MaxLen, MaxLen, false);
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			int i = rand() % 2;
			matrix[x][y] = getFromBool(i);
		}
	}

	print_matrix(matrix);

	cout << endl << "Type the coordinates you want to paint (Row and Column): ";
	cin >> pos1 >> pos2;
	cout << endl << "What color you want to paint with (char): ";
	cin >> cor;
	bool newval = false;
	if (cor == 1)
		newval = true;
	int size = filler.floodfill(matrix, pos1, pos2, newval);
	print_matrix(matrix);
	cout << endl;
	cout << "Chamber was " << size << " cells large" << endl;
	cout << endl;
}

void sizeTest()
{
	srand(time(NULL));

	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
	int** matrix = dynInitaliser::makeInt(MaxLen, MaxLen, 0);
	ifstream fileMatrix;
	fileMatrix.open("matrix.txt");
	if (!fileMatrix.is_open())
	{
		cout << "No file found!" << endl;
	}

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			fileMatrix >> matrix[i][j];
		}
	}

	print_matrix(matrix);

	cout << endl << "Type the coordinates you want to paint (Row and Column): ";
	cin >> pos1 >> pos2;
	cout << endl << "What color you want to paint with (char): ";
	cin >> cor;
	int size = filler.getSize(matrix, pos1, pos2);
	print_matrix(matrix);
	cout << endl;
	cout << "Chamber was " << size << " cells large" << endl;
	cout << endl;
}

void sizeArrayTest()
{
	int pos1, pos2;
	floodfillersize filler = floodfillersize(Width, Height);
	int** matrix = dynInitaliser::makeInt(MaxLen, MaxLen, 0);
	int** sizeArr = dynInitaliser::makeInt(MaxLen, MaxLen, 0);
	ifstream fileMatrix;
	fileMatrix.open("matrix.txt");
	if (!fileMatrix.is_open())
	{
		cout << "No file found!" << endl;
	}

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			fileMatrix >> matrix[i][j];
		}
	}

	print_matrix(matrix);

	filler.getSizeArray(matrix, sizeArr, Width, Height);
	print_matrix(sizeArr);

	//delete array
	dynInitaliser::del(sizeArr, Width);//cleaning up
}


void sizeArrayTestBool()
{
	Width = 6;
	Height = 6;

	int pos1, pos2;
	floodfillersize filler = floodfillersize(Width, Height);
	bool** matrix = dynInitaliser::makeBool(MaxLen, MaxLen, false);
	int** sizeArr = dynInitaliser::makeInt(MaxLen, MaxLen, 0);
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			int i = rand() % 2;
			matrix[x][y] = getFromBool(i);
		}
	}

	print_matrix(matrix);

	filler.getSizeArray(matrix, sizeArr, Width, Height);
	print_matrix(sizeArr);

	//cleanup
	dynInitaliser::del(sizeArr, Width);
}

/////////////
//main program
/////////////
int main()
{
	//intTest();
	//boolTest();
	//sizeTest();
	//sizeArrayTest();
	sizeArrayTestBool();
	system("PAUSE");
	return 0;
}