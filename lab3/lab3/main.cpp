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

	system("pause");
	return 0;
}