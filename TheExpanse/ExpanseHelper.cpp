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

Matrix ExpanseHelper::getTranslationMatrix(double xChange, double yChange)
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

Matrix ExpanseHelper::getScalingMatrix(double xScale, double yScale)
{
	Matrix scalingMatrix(2, 2);
	scalingMatrix.mData[0][0] = xScale;
	scalingMatrix.mData[0][1] = 0;

	scalingMatrix.mData[1][0] = 0;
	scalingMatrix.mData[1][1] = yScale;

	return scalingMatrix;
}

TwoDObject ExpanseHelper::scaleOnLocation(TwoDObject& object, double xScale, double yScale)
{
	TwoDObject newObject;
	std::tuple<double, double> center = object.getCenter();
	Matrix translationMatrixToOrigin = getTranslationMatrix(-std::get<0>(center), -std::get<1>(center));
	Matrix translationMatrixBack = getTranslationMatrix(std::get<0>(center), std::get<1>(center));
	Matrix scalingMatrix = getScalingMatrix(xScale, yScale);

	//Translate to origin
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixToOrigin * object.lines[i].start, translationMatrixToOrigin * object.lines[i].end };
	}

	//Scale
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { scalingMatrix * newObject.lines[i].start, scalingMatrix * newObject.lines[i].end };
	}

	////Tanslate back
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixBack * newObject.lines[i].start, translationMatrixBack * newObject.lines[i].end };
	}

	return newObject;
}

Matrix ExpanseHelper::getRotationMatrix(double degrees)
{
	Matrix rotationMatrix(3, 3);
	double PI = 3.14159265358979323846264338327950288419;

	rotationMatrix.mData[0][0] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[0][1] = -sin(degrees * PI / 180.0);
	rotationMatrix.mData[0][2] = 0;

	rotationMatrix.mData[1][0] = sin(degrees * PI / 180.0);
	rotationMatrix.mData[1][1] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[1][2] = 0;

	rotationMatrix.mData[2][0] = 0;
	rotationMatrix.mData[2][1] = 0;
	rotationMatrix.mData[2][2] = 1;

	return rotationMatrix;
}

TwoDObject ExpanseHelper::rotate(TwoDObject& object, double degrees)
{
	TwoDObject newObject;
	std::tuple<double, double> center = object.getCenter();
	Matrix translationMatrixToOrigin = getTranslationMatrix(-std::get<0>(center), -std::get<1>(center));
	Matrix translationMatrixBack = getTranslationMatrix(std::get<0>(center), std::get<1>(center));
	Matrix rotationMatrix = getRotationMatrix(degrees);

	//Translate to origin
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixToOrigin * object.lines[i].start, translationMatrixToOrigin * object.lines[i].end };
	}

	//Rotate
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { rotationMatrix * newObject.lines[i].start, rotationMatrix * newObject.lines[i].end };
	}

	//Translate back
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrixBack * newObject.lines[i].start, translationMatrixBack * newObject.lines[i].end };
	}

	
	return newObject;
}

TwoDObject ExpanseHelper::rotateAroundOrigin(TwoDObject& object, double degrees)
{
	TwoDObject newObject;
	Matrix rotationMatrix = getRotationMatrix(degrees);

	//Rotate
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { rotationMatrix * object.lines[i].start, rotationMatrix * object.lines[i].end };
	}

	return newObject;
}

TwoDObject ExpanseHelper::translateMatrix(TwoDObject& object, double xChange, double yChange) {
	TwoDObject newObject;
	Matrix translationMatrix = getTranslationMatrix(xChange, yChange);
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrix * object.lines[i].start, translationMatrix * object.lines[i].end };
	}
	return newObject;
}

