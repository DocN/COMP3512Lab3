#include <iostream>
#include "Matrix.hpp"
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <array>
#include <vector>

using namespace std;

Matrix::Matrix() {
	myMatrix = new int*[DEFAULT_SIZE];
	allocateArray(DEFAULT_SIZE);
	matrixSize = DEFAULT_SIZE;
}

Matrix::Matrix(int A[], int n) {
	int dimension = 1;
	if (checkSquarable(n)) {
		dimension = sqrt(1);
	}
	else {
		cout << "invalid number of elements, made 1 by 1 matrix " << endl;
	}
	myMatrix = new int*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
}

Matrix::Matrix(int dimension) {
	myMatrix = new int*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
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

void Matrix::fillTester() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = 1;
		}
	}
}

void Matrix::printMatrix() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << myMatrix[i][j];
		}
		cout << endl;
	}
}

void Matrix::set_Value(int x, int y, int value) {
	myMatrix[x][y] = value;
}

int Matrix::get_Value(int x, int y) {
	return myMatrix[x][y];
}

void Matrix::clearArray() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = 0;
		}
	}
}

Matrix * Matrix::identity() {
	return new Matrix(matrixSize);
}