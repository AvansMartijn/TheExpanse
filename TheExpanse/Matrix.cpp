#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int rows, int cols)
{
	_rows = rows;
	_cols = cols;

	for (int i = 0; i < rows; i++)
	{
		std::vector<double> newRow;
		for (int i = 0; i < cols; i++)
		{
			newRow.push_back(0);
		}
		mData.push_back(newRow);
	}
}

Matrix::Matrix(std::vector<std::vector<double>> data)
{
	mData = data;
	_rows = data.size();
	_cols = data[0].size();
}

Matrix Matrix::operator+(const Matrix& operand)
{
	if (_rows != operand._rows) {
		throw std::invalid_argument("Matrice Must have same amount of rows");
	}
	if (_cols != operand._cols) {
		throw std::invalid_argument("Matrice Must have same amount of cols");
	}

	Matrix newMatrix(mData.size(), mData[0].size());

	for (int i = 0; i < mData.size(); i++)
	{
		for (int j = 0; j < mData[0].size(); j++)
		{
			newMatrix.mData[i][j] = mData[i][j] + operand.mData[i][j];
		}

	}
	return newMatrix;
}

Matrix Matrix::operator-(const Matrix& operand)
{
	if (_rows != operand._rows) {
		throw std::invalid_argument("Matrice Must have same amount of rows");
	}
	if (_cols != operand._cols) {
		throw std::invalid_argument("Matrice Must have same amount of cols");
	}

	Matrix newMatrix(mData.size(), mData[0].size());

	for (int i = 0; i < mData.size(); i++)
	{
		for (int j = 0; j < mData[0].size(); j++)
		{
			newMatrix.mData[i][j] = mData[i][j] - operand.mData[i][j];
		}

	}
	return newMatrix;
}

Matrix Matrix::operator*(int scalar)
{
	std::vector<std::vector<double>> newData;
	for (int i = 0; i < mData.size(); i++)
	{
		std::vector<double> newRow;
		for (int j = 0; j < mData.at(i).size(); j++)
		{
			newRow.push_back(mData.at(i).at(j) * scalar);
		}
		newData.push_back(newRow);
	}
	return Matrix(newData);
}

Vector Matrix::operator*(const Vector& operand)
{
	Matrix tempMatrix(3, 1);
	tempMatrix.mData[0][0] = operand.x;
	tempMatrix.mData[1][0] = operand.y;
	tempMatrix.mData[2][0] = 1;

	if (_cols != tempMatrix._rows) {
		throw std::invalid_argument("Columns of A do not match Rows of B");
	}

	Matrix newMatrix(3, 1);

	for (int i = 0; i < _rows; ++i)
		for (int k = 0; k < _cols; ++k)
		{
			newMatrix.mData[i][0] += mData[i][k] * tempMatrix.mData[k][0];
		}

	Vector newVector{ newMatrix.mData[0][0], newMatrix.mData[1][0] };

	return newVector;
}

Matrix Matrix::operator*(const Matrix& operand)
{
	if (_cols != operand._rows) {
		throw std::invalid_argument("Columns of A do not match Rows of B");
	}

	Matrix newMatrix(3, 3);

	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < operand._cols; ++j)
			for (int k = 0; k < _cols; ++k)
			{
				newMatrix.mData[i][j] += mData[i][k] * operand.mData[k][j];
			}

	return newMatrix;
}