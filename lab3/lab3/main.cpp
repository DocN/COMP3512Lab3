#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main() {
	int dimension = 9;
	Matrix * test = new Matrix(dimension);
	test->fillTester();
	system("pause");
	return 0;
}