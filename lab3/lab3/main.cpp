#include <iostream>
#include "Matrix.hpp"
#include <array>

using namespace std;

int main() {
	int foo[9] = { 16, 2, 77, 40, 12071, 200,100,1000,1 };
	Matrix * test = new Matrix(foo, 9);
	test->fillTester();
	test->printMatrix();
	system("pause");
	return 0;
}