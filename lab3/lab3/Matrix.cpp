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
	int A[DEFAULT_SIZE] = { 0 };
	fillMatrix(A, DEFAULT_SIZE);
}

Matrix::Matrix(int A[], int n) {
	int dimension = 1;
	if (checkSquarable(n)) {
		dimension = sqrt(n);
	}
	else {
		cout << "invalid number of elements, made 1 by 1 matrix " << endl;
	}
	myMatrix = new int*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
	fillMatrix(A, n);
}

Matrix::Matrix(int dimension) {
	myMatrix = new int*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
}

Matrix::~Matrix() {
	for (int i = 0; i < matrixSize; i++) {
		delete myMatrix[i];
	}
	delete myMatrix;
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

void Matrix::printMatrix() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << myMatrix[i][j] << " ";
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

void Matrix::fillMatrix(int A[], int n) {
	int arrayCount = 0;
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = A[arrayCount];
			arrayCount++;
		}
	}
}

Matrix * Matrix::identity() {
	Matrix * newIdentity = new Matrix(matrixSize);
	for (int i = 0; i < newIdentity->matrixSize; i++) {
		for (int j = 0; j < newIdentity->matrixSize; j++) {
			if (i == j) {
				newIdentity->set_Value(i, j, 1);
			}
			else {
				newIdentity->set_Value(i, j, 0);
			}
		}
	}
	return newIdentity;
}

ostream& operator<<(ostream& os, const Matrix& theMatrix)
{
	for (int i = 0; i < theMatrix.matrixSize; i++) {
		for (int j = 0; j < theMatrix.matrixSize; j++) {
			os << theMatrix.myMatrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

bool operator== (const Matrix &m1, const Matrix &m2) {
	//check if they're the same size
	if (m1.matrixSize == m2.matrixSize) {
		for (int i = 0; i < m1.matrixSize; i++) {
			for (int j = 0; j < m1.matrixSize; j++) {
				//check each element to see if they're equal
				if (!(m1.myMatrix[i][j] == m2.myMatrix[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool operator!= (const Matrix &m1, const Matrix &m2) {
	if (m1 == m2) {
		return false;
	}
	return true;
}

bool operator< (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize < m2.matrixSize) {
		return true;
	}
	return false;
}

bool operator<= (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize < m2.matrixSize || m1 == m2) {
		return true;
	}
	return false;
}

bool operator> (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize > m2.matrixSize) {
		return true;
	}
	return false;
}

bool operator>= (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize > m2.matrixSize || m1 == m2) {
		return true;
	}
	return false;
}

void Matrix::operator++() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			int currentVal = get_Value(i, j) + 1;
			set_Value(i, j, currentVal);
		}
	}
}

void Matrix::operator++(int) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			int currentVal = get_Value(i, j) + 1;
			set_Value(i, j, currentVal);
		}
	}
}

void Matrix::operator--() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			int currentVal = get_Value(i, j) - 1;
			set_Value(i, j, currentVal);
		}
	}
}

void Matrix::operator--(int) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			int currentVal = get_Value(i, j) - 1;
			set_Value(i, j, currentVal);
		}
	}

}

Matrix& Matrix::operator=(Matrix &rhs) {
	swap(*this, rhs); 
	return *this; 
}

Matrix& Matrix::operator+=(Matrix& rhs) {
	if (rhs.matrixSize != matrixSize) {
		cout << "invalid summation, matrixes aren't the same size" << endl;
	}
	else {
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				int newVal = myMatrix[i][j] + rhs.myMatrix[i][j]; 
				set_Value(i, j, newVal);
			 }
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(Matrix& rhs) {
	if (rhs.matrixSize != matrixSize) {
		cout << "invalid summation, matrixes aren't the same size" << endl;
	}
	else {
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				int newVal = myMatrix[i][j] - rhs.myMatrix[i][j];
				set_Value(i, j, newVal);
			}
		}
	}
	return *this;
}

Matrix& operator+(const Matrix& a, const Matrix& b) {
	Matrix * newMatrix = new Matrix(a.matrixSize);
	if (a.matrixSize == b.matrixSize) {
		for (int i = 0; i < a.matrixSize; i++) {
			for (int j = 0; j < a.matrixSize; j++) {
				int newVal = a.myMatrix[i][j] + b.myMatrix[i][j];
				newMatrix->myMatrix[i][j] = newVal;
			}
		}
	}
	return *newMatrix;
}

Matrix& operator-(const Matrix& a, const Matrix& b) {
	Matrix * newMatrix = new Matrix(a.matrixSize);
	if (a.matrixSize == b.matrixSize) {
		for (int i = 0; i < a.matrixSize; i++) {
			for (int j = 0; j < a.matrixSize; j++) {
				int newVal = a.myMatrix[i][j] - b.myMatrix[i][j];
				newMatrix->myMatrix[i][j] = newVal;
			}
		}
	}
	return *newMatrix;
}



