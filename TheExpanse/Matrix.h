#pragma once
#include <vector>
#include "Vector.h"
class Matrix
{
public:
	int matrix[10][10];
	Matrix();
	Matrix operator*(int operand);
	//int getAmountOfRows();
	//int getAmountOfCols();
	//Matrix(std::vector<std::vector<int>> values);
	//std::vector<std::vector<int>> values;
	///*Vector operator+(const Vector& operand);
	//Vector operator-(const Vector& operand);*/
	///*Vector operator+(int operand);
	//Vector operator-(int operand);*/
	//Matrix operator*(const Vector& operand);
	//Matrix operator*(const Matrix& operand);
	//Matrix operator*(int operand);
	//void printMatrixToConsole();
};

