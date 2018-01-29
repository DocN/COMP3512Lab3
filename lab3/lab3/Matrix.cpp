#include <iostream>
#include "Matrix.hpp"
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

using namespace std;

Matrix::Matrix() {
	myMatrix = new int*[DEFAULT_SIZE];
	allocateArray(DEFAULT_SIZE);
}

Matrix::Matrix(int dimension) {
	myMatrix = new int*[dimension];

	//check if it's a square otherwise implement it as a default size 
	if (checkSquarable(dimension) && dimension >= 1) {
		allocateArray(dimension);
		matrixSize = dimension;
		return;
	}
	cout << "Invalid array dimension set as default " << DEFAULT_SIZE << endl;
	allocateArray(DEFAULT_SIZE);
	matrixSize = DEFAULT_SIZE;
}

void Matrix::allocateArray(int dimension) {
	for (int i = 0; i < dimension; i++) {
		myMatrix[i] = new int[dimension];
	}
}

bool Matrix::checkSquarable(int number) {
	double tempNumber = number;
	int fullNumber = sqrt(number);
	tempNumber = sqrt(tempNumber);
	tempNumber = tempNumber - fullNumber;
	if (tempNumber > 0) {
		return false;
	}
	return true;
}


void Matrix::set_Value(int x, int y, int value) {
	myMatrix[x][y] = value;
}

void Matrix::fillTester() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = 1;
		}
	}
}