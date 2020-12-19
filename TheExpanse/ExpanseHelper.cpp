#include "ExpanseHelper.h"

void ExpanseHelper::printMatrix(const Matrix& m)
{
	std::vector<std::vector<double>> newData;
	for (size_t i = 0; i < m.mData.size(); i++)
	{
		std::vector<double> newRow;
		for (size_t j = 0; j < m.mData.at(i).size(); j++)
		{
			std::cout << (m.mData.at(i).at(j)) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

Matrix ExpanseHelper::getTranslationMatrix(int xChange, int yChange)
{
	Matrix translationMatrix(3, 3);
	translationMatrix.mData[0][0] = 1;
	translationMatrix.mData[0][1] = 0;
	translationMatrix.mData[0][2] = xChange;

	translationMatrix.mData[1][0] = 0;
	translationMatrix.mData[1][1] = 1;
	translationMatrix.mData[1][2] = yChange;

	translationMatrix.mData[2][0] = 0;
	translationMatrix.mData[2][1] = 0;
	translationMatrix.mData[2][2] = 1;

	return translationMatrix;
}

Matrix ExpanseHelper::getScalingMatrix(int xScale, int yScale)
{
	Matrix scalingMatrix(2, 2);
	scalingMatrix.mData[0][0] = xScale;
	scalingMatrix.mData[0][1] = 0;

	scalingMatrix.mData[1][0] = 0;
	scalingMatrix.mData[1][1] = yScale;

	return scalingMatrix;
}

TwoDObject ExpanseHelper::scaleOnLocation(TwoDObject& object, int xScale, int yScale)
{
	TwoDObject newObject;
	std::tuple<int, int> center = object.getCenter();
	Matrix translationMatrixToOrigin = getTranslationMatrix(-std::get<0>(object.getCenter()), -std::get<1>(object.getCenter()));
	Matrix translationMatrixBack = getTranslationMatrix(std::get<0>(object.getCenter()), std::get<1>(object.getCenter()));
	Matrix scalingMatrix = getScalingMatrix(2, 2);

	//Translate to origin
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixToOrigin * std::get<0>(object.lines[i]), translationMatrixToOrigin * std::get<1>(object.lines[i]) };
	}

	//Scale
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { scalingMatrix * std::get<0>(newObject.lines[i]), scalingMatrix * std::get<1>(newObject.lines[i]) };
	}

	//Tanslate back
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixBack * std::get<0>(newObject.lines[i]), translationMatrixToOrigin * std::get<1>(newObject.lines[i]) };
	}

	return newObject;
}

