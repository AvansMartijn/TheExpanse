#pragma once

#include <vector>
#include "Vector.h"
class Matrix
{
	/*						Second ->
	* First Direction Down	[ 0 5 8]
	*						[ 2 8 9]
	* So mData[0][1] = 5
	*/
public:
	Matrix(int rows, int cols);
	Matrix(std::vector<std::vector<double>> data);

	//ADD
	Matrix operator+(const Matrix& operand);

	//SUBTRACT
	Matrix operator-(const Matrix& operand);

	//MULTIPLY
	Matrix operator*(int scalar);
	Vector operator*(const Vector& operand);
	Matrix operator*(const Matrix& operand);

	std::vector<std::vector<double>> mData;

private:
	int _rows;
	int _cols;
};