#pragma once
#include <vector>
#include "Vector.h"
class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(std::vector<std::vector<double>> data);
	double getValue(int row, int col);
	void setValue(int row, int col, double value);
	Matrix operator*(int scalar);
	Matrix operator*(Matrix operand);

	void printMatrix();
	std::vector<std::vector<double>> mData;

private:
	/*						Second ->
	* First Direction Down	[ 0 5 8]
	*						[ 2 8 9]
	* So mData[0][1] = 5
	*/
};

