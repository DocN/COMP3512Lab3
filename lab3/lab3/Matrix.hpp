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
	friend bool operator== (const Matrix &m1, const Matrix &m2);
	friend bool operator!= (const Matrix &m1, const Matrix &m2);
	friend bool operator< (const Matrix &m1, const Matrix &m2);
	friend bool operator<= (const Matrix &m1, const Matrix &m2);
	friend bool operator> (const Matrix &m1, const Matrix &m2);
	friend bool operator>= (const Matrix &m1, const Matrix &m2);
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
	Matrix& operator=(Matrix rhs);
	Matrix & Matrix::operator+=(Matrix &rhs);

private:
	static const int DEFAULT_SIZE = 1;
	int  ** myMatrix;
	int matrixSize;
};

