#include <iostream>
#include "Matrix.hpp"
#include <array>

using namespace std;

int main() {
	int foo[9] = { 16, 2, 77, 40, 12071, 200,100,1000,1 };
	Matrix * test = new Matrix(foo, 9);
	Matrix * test2 = new Matrix(foo, 9);

	cout << *test;

	if (*test2 == *test) {
		cout << "they're equal " << endl;
	}

	if (*test2 != *test) {
		cout << "not equal " << endl;
	}
	else {
		cout << "equal " << endl;
	}

	if (*test > *test2) {
		cout << "test1 is greater than test2" << endl;
	}
	else {
		cout << "test1 is not greater than test2" << endl;
	}

	if (*test >= *test2) {
		cout << "test1 is greater than or equal to test2" << endl;
	}
	else {
		cout << "test1 is not greater than or equal to test2" << endl;
	}

	if (*test <= *test2) {
		cout << "test1 is less than or equal to test2" << endl;
	}
	else {
		cout << "test1 is not less than test2" << endl;
	}

	if (*test < *test2) {
		cout << "test1 is less than test2" << endl;
	}
	else {
		cout << "test1 is not less than test2" << endl;
	}


	Matrix * newMatrix = test->identity();
	cout << *newMatrix;
	system("pause");
	return 0;
}