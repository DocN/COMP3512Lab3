#pragma once
#include <iostream> 

using namespace std;


class Matrix {
public:
	Matrix();
	Matrix(int);
	void allocateArray(int);
	bool checkSquarable(int);
	void set_Value(int, int, int);
	void fillTester();

private:
	static const int DEFAULT_SIZE = 1;
	int  ** myMatrix;
	int matrixSize;
};

