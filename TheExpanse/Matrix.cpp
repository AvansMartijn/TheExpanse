#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		std::vector<double> newRow;
		for (size_t i = 0; i < cols; i++)
		{
			newRow.push_back(0);
		}
		mData.push_back(newRow);
	}
}

Matrix::Matrix(std::vector<std::vector<double>> data)
{
	mData = data;
}

double Matrix::getValue(int row, int col)
{
	return mData.at(row).at(col);
}

void Matrix::setValue(int row, int col, double value)
{
	mData[row][col] = value;
}

Matrix Matrix::operator*(int scalar)
{
	std::vector<std::vector<double>> newData;
	for (size_t i = 0; i < mData.size(); i++)
	{
		std::vector<double> newRow;
		for (size_t j = 0; j < mData.at(i).size(); j++)
		{
			newRow.push_back(mData.at(i).at(j) * scalar);
		}
		newData.push_back(newRow);
	}
	return Matrix(newData);
}

Matrix Matrix::operator*(Matrix operand)
{
	Matrix newMatrix(3, 3);

	for (size_t i = 0; i < mData.size(); i++)
	{
		for (size_t j = 0; j < operand.mData.size(); j++)
		{
			newMatrix.mData[i][j] = mData[i][0] * operand.mData[0][j] + mData[i][1] * operand.mData[1][j] + mData[i][2] * operand.mData[2][j];
		}
	}
	return newMatrix;
}

void Matrix::printMatrix()
{
	std::vector<std::vector<double>> newData;
	for (size_t i = 0; i < mData.size(); i++)
	{
		std::vector<double> newRow;
		for (size_t j = 0; j < mData.at(i).size(); j++)
		{
			std::cout << (mData.at(i).at(j)) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

