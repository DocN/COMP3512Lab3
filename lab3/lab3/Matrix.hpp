#pragma once
#include <iostream> 

using namespace std;


class Matrix {
public:
	Matrix();
	Matrix(int);
	void allocateArray(int);
	bool checkSquarable(int);

private:
	static const int DEFAULT_SIZE = 1;
	int  ** myMatrix;
};

