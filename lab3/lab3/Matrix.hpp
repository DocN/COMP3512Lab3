#pragma once
#include <iostream> 

using namespace std;


class Matrix {
public:
	Matrix();
	Matrix(int A [], int n);
	Matrix(int);
	~Matrix();
	void allocateArray(int);
	bool checkSquarable(int);
	void fillTester();
	void printMatrix();
	void set_Value(int, int, int);
	int get_Value(int, int);
	void clearArray();
	Matrix * identity();
	void fillMatrix(int A[], int);

	friend ostream& operator<<(ostream& os, const Matrix& theMatrix);

private:
	static const int DEFAULT_SIZE = 1;
	int  ** myMatrix;
	int matrixSize;
};

