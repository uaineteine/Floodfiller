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
	int matrix[MaxLen][MaxLen];

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
	if ((filler.verify_start(pos1, pos2)))
	{
		cout << endl << "What color you want to paint with (char): ";
		cin >> cor;
		int size = filler.floodfill(matrix, pos1, pos2, cor);
		print_matrix(matrix);
		cout << endl;
		cout << "Chamber was " << size << " cells large" << endl;
		cout << endl;
	}
	else
	{
		cout << endl << "Invalid Position!" << endl;
	}
}

void boolTest()
{
	/* initialize random seed: */
	srand(time(NULL));

	int pos1, pos2;
	int cor;
	floodfiller filler = floodfiller(Width, Height);
	bool matrix[MaxLen][MaxLen];
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
	if ((filler.verify_start(pos1, pos2)))
	{
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
	else
	{
		cout << endl << "Invalid Position!" << endl;
	}
}

void sizeTest()
{
	/* initialize random seed: */
	srand(time(NULL));

	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
	bool matrix[MaxLen][MaxLen];
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
	if ((filler.verify_start(pos1, pos2)))
	{
		cout << endl << "What color you want to paint with (char): ";
		cin >> cor;
		bool newval = false;
		if (cor == 1)
			newval = true;
		int size = filler.getSize(matrix, pos1, pos2, newval);
		print_matrix(matrix);
		cout << endl;
		cout << "Chamber was " << size << " cells large" << endl;
		cout << endl;
	}
	else
	{
		cout << endl << "Invalid Position!" << endl;
	}
}

void sizeArrayTest()
{

	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
	int matrix[MaxLen][MaxLen];
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

	int** sizeArr = filler.getSizeArr(matrix);
	print_matrix(sizeArr);

	//delete array
	for (int x = 0; x < Width; x++)
	{
		delete[] sizeArr[x];
	}
	delete[] sizeArr;
	sizeArr = 0;
}

void sizeArrayTestBool()
{
	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
	bool matrix[MaxLen][MaxLen];
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			int i = rand() % 2;
			matrix[x][y] = getFromBool(i);
		}
	}

	print_matrix(matrix);

	int** sizeArr = filler.getSizeArr(matrix);
	print_matrix(sizeArr);

	//delete array
	for (int x = 0; x < Width; x++)
	{
		delete[] sizeArr[x];
	}
	delete[] sizeArr;
	sizeArr = false;
}

void DynMapTest()
{
	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
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

	int** sizeArr = filler.getSizeArr(matrix);
	print_matrix(sizeArr);

	//delete array
	for (int x = 0; x < Width; x++)
	{
		delete[] sizeArr[x];
	}
	delete[] sizeArr;
	sizeArr = false;
}

void SizeTest()
{
	//make a bit larger for test
	Width = 40;
	Height = 40;

	int pos1, pos2;
	int cor;
	floodfillersize filler = floodfillersize(Width, Height);
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

	int** sizeArr = filler.getSizeArr(matrix);
	print_matrix(sizeArr);

	//delete array
	for (int x = 0; x < Width; x++)
	{
		delete[] sizeArr[x];
	}
	delete[] sizeArr;
	sizeArr = false;
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
	//sizeArrayTestBool();
	//DynMapTest();
	SizeTest();
	system("PAUSE");
	return 0;
}