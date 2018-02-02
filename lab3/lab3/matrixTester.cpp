#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main() {
	//testing empty constructor init
	Matrix * test = new Matrix();
	cout << "testing empty array build " << endl;
	cout << *test << endl;
	cout << endl;

	//testing matrix init with size and array
	cout << "testing matrix init with size and array" << endl;
	int A[9] = { 1,2,3,4,5,6,7,8,9 };
	Matrix * test2 = new Matrix(A, 9);
	cout << *test2 << endl;
	cout << endl;

	//testing non square matrix init 
	int B[8] = { 1,2,3,4,5,6,7,8 };
	Matrix * test3 = new Matrix(B, 8);
	cout << *test3 << endl;
	cout << endl;

	//testing print function for matrix 
	cout << "testing print function for matrix " << endl;
	test2->printMatrix();
	cout << endl;

	//testing set value 
	cout << "testing set value x= 1 y = 1 val = 2 " << endl;
	test2->set_Value(1, 1, 2);
	cout << *test2;
	cout << endl;

	//testing get value 
	cout << "testing get value x = 2, y = 2 " << endl;
	cout << "expected 9 and got " << test2->get_Value(2, 2) << endl;
	cout << endl;

	//test identity matrix generate from matrix 
	cout << "test identity matrix generate from matrix " << endl;
	Matrix * newIdentity = test2->identity();
	cout << *newIdentity;
	cout << endl;

	//test output stream 
	cout << "testing overloaded output stream << " << endl;
	cout << *newIdentity;
	cout << *test2;
	cout << endl;

	//testing equal equal operator 
	cout << "testing equal equal operator " << endl;
	Matrix * test4 = new Matrix(A, 9);
	Matrix * test5 = new Matrix(A, 9);
	if ((*test4) == (*test5)) {
		cout << "they're equal" << endl;
	}
	cout << endl;

	//testing greater than operator
	if ((*test4) > (*test2)) {
		cout << "test4 is greater than test2" << endl;
	}
	else {
		cout << "test4 is not greater than test2" << endl;
	}
	cout << endl;

	//testing greater than equal operator
	if ((*test4) >= (*test2)) {
		cout << "test4 is greater than or equal to test2" << endl;
	}
	else {
		cout << "test4 is not greater than or equal to test2" << endl;
	}
	//testing greater than equal operator
	if ((*test2) >= (*test2)) {
		cout << "test2 is greater than or equal to test2" << endl;
	}
	else {
		cout << "test2 is not greater than or equal to test2" << endl;
	}
	cout << endl;


	//testing greater than equal operator
	if ((*test4) <= (*test2)) {
		cout << "test4 is less than or equal to test2" << endl;
	}
	else {
		cout << "test2 is not less than or equal to test2" << endl;;
	}
	//testing greater than equal operator
	if ((*test2) <= (*test2)) {
		cout << "test2 is less than or equal to test2" << endl;
	}
	else {
		cout << "test2 is not less than or equal to test2" << endl;
	}
	cout << endl;

	//testing pre and post increment
	cout << "testing pre increment " << endl;
	cout << *test2;
	cout << (++(*test2));

	cout << "testing post increment " << endl;
	cout << *test2;
	cout << ((*test2)++);
	if (((*test2)++) == (*test2)) {
		cout << "they're equal test2 test2++" << endl;
		cout << *test2;
	}
	cout << endl;

	//testing pre and post increment
	cout << "testing pre deincrement " << endl;
	cout << *test2;
	--(*test2);
	cout << *test2;

	cout << "testing post deincrement " << endl;
	cout << *test2;
	(*test2)--;
	cout << *test2;
	cout << endl;

	//testing equals operator
	cout << "testing equals operator " << endl;
	Matrix * test7 = test2->identity();
	Matrix test6 = *test7;
	cout << test6;
	cout << *test2;

	cout << "test here" << endl;
	test6.set_Value(1, 1, 12);
	cout << test6;
	cout << *test2;

	cout << endl;

	//testing += opreator
	cout << "testing += operator " << endl;
	cout << test6;
	cout << *test2;
	cout << "sum of the two" << endl;
	test6 += *test2;
	cout << test6;

	//testing -= opreator
	cout << "testing -= operator " << endl;
	cout << test6;
	cout << *test2;
	cout << "subtraction of the two" << endl;
	test6 -= *test2;
	cout << test6;
	cout << *test2;


	//testing + operator
	cout << "testing + operator " << endl;
	cout << test6;
	cout << *test2;

	cout << (test6)+(*test2);

	//testing - operator
	cout << "testing - operator " << endl;
	cout << test6;
	cout << *test2;

	cout << (test6)-(*test2);

	system("pause");
	return 0;
}
