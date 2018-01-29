#include <iostream>
#include "Matrix.hpp"

using namespace std;

Matrix::Matrix() {
	myMatrix = new int*[DEFAULT_SIZE];
	allocateArray(DEFAULT_SIZE);
}

Matrix::Matrix(int dimension) {
	myMatrix = new int*[dimension];
	allocateArray(dimension);
}

void Matrix::allocateArray(int dimension) {
	for (int i = 0; i < dimension; i++) {
		myMatrix[i] = new int[dimension];
	}
}

