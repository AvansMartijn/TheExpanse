#include "Matrix.h"
#include <iostream>

//int Matrix::getAmountOfRows()
//{
//	return values.size();
//}
//
//int Matrix::getAmountOfCols()
//{
//	return values.at(0).size();
//}
//
//Matrix::Matrix(std::vector<std::vector<int>> newValues) {
//	values = newValues;
//}
//
//Matrix Matrix::operator*(const Vector& operand)
//{
//	return Matrix{ values };
//}
//
//Matrix Matrix::operator*(const Matrix& operand)
//{
//	//if columns amount of matrix A == rows amount of operand matrix
//	//we can multiply
//	if (values.at(0).size() == operand.values.size()) {
//		std::vector<std::vector<int>> newValues;
//		//multiply each ROW from A with COL from B
//		for (int rowA = 0; rowA < values.size(); rowA++) {
//			std::vector<int> newCol;
//			newValues.push_back(newCol);
//			for (int colA = 0; colA < operand.values.at(rowA).size(); colA++) {
//				newValues.at(rowA).push_back(values.at(rowA).at(colA) * operand.values.at(colA).at(rowA));
//			}
//		}
//	}
//}
//
//Matrix Matrix::operator*(int operand)
//{
//	std::vector<std::vector<int>> newValues;
//	for (int row = 0; row < values.size(); row++) {
//		std::vector<int> newCol;
//		newValues.push_back(newCol);
//		for (int col = 0; col < values.at(row).size(); col++) {
//			newValues.at(row).push_back(values.at(row).at(col) * operand);
//		}
//	}
//	return Matrix(newValues);
//}
//
//void Matrix::printMatrixToConsole() {
//	for (int row = 0; row < values.size(); row++) {
//		for (int col = 0; col < values.at(row).size(); col++) {
//			std::cout << "row: " << row << " col: " << col << " val: " << values.at(row).at(col) << "\n";
//		}
//	}
//}

