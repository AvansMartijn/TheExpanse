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

Matrix ExpanseHelper::getTranslationMatrix(double xChange, double yChange, double zChange)
{
	Matrix translationMatrix(4, 4);
	translationMatrix.mData[0][0] = 1;
	translationMatrix.mData[0][1] = 0;
	translationMatrix.mData[0][2] = 0;
	translationMatrix.mData[0][3] = xChange;

	translationMatrix.mData[1][0] = 0;
	translationMatrix.mData[1][1] = 1;
	translationMatrix.mData[1][2] = 0;
	translationMatrix.mData[1][3] = yChange;

	translationMatrix.mData[2][0] = 0;
	translationMatrix.mData[2][1] = 0;
	translationMatrix.mData[2][2] = 1;
	translationMatrix.mData[2][3] = zChange;

	translationMatrix.mData[3][0] = 0;
	translationMatrix.mData[3][1] = 0;
	translationMatrix.mData[3][2] = 0;
	translationMatrix.mData[3][3] = 1;

	return translationMatrix;
}

Matrix ExpanseHelper::getScalingMatrix(double xScale, double yScale, double zScale)
{
	Matrix scalingMatrix(4, 4);
	scalingMatrix.mData[0][0] = xScale;
	scalingMatrix.mData[0][1] = 0;
	scalingMatrix.mData[0][2] = 0;
	scalingMatrix.mData[0][3] = 0;

	scalingMatrix.mData[1][0] = 0;
	scalingMatrix.mData[1][1] = yScale;
	scalingMatrix.mData[1][2] = 0;
	scalingMatrix.mData[1][3] = 0;

	scalingMatrix.mData[2][0] = 0;
	scalingMatrix.mData[2][1] = 0;
	scalingMatrix.mData[2][2] = zScale;
	scalingMatrix.mData[2][3] = 0;

	scalingMatrix.mData[3][0] = 0;
	scalingMatrix.mData[3][1] = 0;
	scalingMatrix.mData[3][2] = 0;
	scalingMatrix.mData[3][3] = 1;

	return scalingMatrix;
}

ThreeDObject ExpanseHelper::scaleOnLocation(ThreeDObject& object, double xScale, double yScale, double zScale)
{
	ThreeDObject newObject;
	newObject.centerPoint = object.centerPoint;
	Matrix translationMatrixToOrigin = getTranslationMatrix(-object.centerPoint.x, -object.centerPoint.y, -object.centerPoint.z);
	Matrix translationMatrixBack = getTranslationMatrix(object.centerPoint.x, object.centerPoint.y, object.centerPoint.z);
	Matrix scalingMatrix = getScalingMatrix(xScale, yScale, zScale);

	Matrix superMatrix = translationMatrixBack * scalingMatrix * translationMatrixToOrigin;

	for (int i = 0; i < newObject.points.size(); i++)
	{
		newObject.points[i] = superMatrix * object.points[i];
	}

	return newObject;
}

Matrix ExpanseHelper::getRotationMatrixZAxis(double degrees)
{
	Matrix rotationMatrix(4, 4);

	rotationMatrix.mData[0][0] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[0][1] = -sin(degrees * PI / 180.0);
	rotationMatrix.mData[0][2] = 0;
	rotationMatrix.mData[0][3] = 0;

	rotationMatrix.mData[1][0] = sin(degrees * PI / 180.0);
	rotationMatrix.mData[1][1] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[1][2] = 0;
	rotationMatrix.mData[1][3] = 0;

	rotationMatrix.mData[2][0] = 0;
	rotationMatrix.mData[2][1] = 0;
	rotationMatrix.mData[2][2] = 1;
	rotationMatrix.mData[2][3] = 0;

	rotationMatrix.mData[3][0] = 0;
	rotationMatrix.mData[3][1] = 0;
	rotationMatrix.mData[3][2] = 0;
	rotationMatrix.mData[3][3] = 1;

	return rotationMatrix;
}
Matrix ExpanseHelper::getRotationMatrixYAxis(double degrees)
{
	Matrix rotationMatrix(4, 4);

	rotationMatrix.mData[0] = { cos(degrees * PI / 180.0), 0, -sin(degrees * PI / 180.0), 0 };
	rotationMatrix.mData[1] = { 0, 1, 0, 0 };
	rotationMatrix.mData[2] = { sin(degrees * PI / 180.0), 0, cos(degrees * PI / 180.0), 0 };
	rotationMatrix.mData[3] = { 0, 0, 0, 1 };

	return rotationMatrix;
}
Matrix ExpanseHelper::getRotationMatrixXAxis(double degrees)
{
	Matrix rotationMatrix(4, 4);

	rotationMatrix.mData[0] = { 1, 0, 0, 0 };
	rotationMatrix.mData[1] = { 0, cos(degrees * PI / 180.0), sin(degrees * PI / 180.0), 0 };
	rotationMatrix.mData[2] = { 0, -sin(degrees * PI / 180.0), cos(degrees * PI / 180.0), 0 };
	rotationMatrix.mData[3] = { 0, 0, 0, 1 };

	return rotationMatrix;
}

ThreeDObject ExpanseHelper::rotate(ThreeDObject& object, double degrees, char axis)
{
	ThreeDObject newObject;
	newObject.centerPoint = object.centerPoint;
	Matrix translationMatrixToOrigin = getTranslationMatrix(-object.centerPoint.x, -object.centerPoint.y, -object.centerPoint.z);
	Matrix translationMatrixBack = getTranslationMatrix(object.centerPoint.x, object.centerPoint.y, object.centerPoint.z);

	Matrix rotationMatrix(1,1);
	switch (axis)
	{
	case 'X':
		rotationMatrix = getRotationMatrixXAxis(degrees);
		break;
	case 'Y':
		rotationMatrix = getRotationMatrixYAxis(degrees);
		break;
	case 'Z':
		rotationMatrix = getRotationMatrixZAxis(degrees);
		break;
	default:
		break;
	}

	Matrix superMatrix = translationMatrixBack * rotationMatrix * translationMatrixToOrigin;
	for (int i = 0; i < newObject.points.size(); i++)
	{
		newObject.points[i] = superMatrix * object.points[i];
	}

	return newObject;
}

ThreeDObject ExpanseHelper::rotateAroundOrigin(ThreeDObject& object, double degrees, char axis)
{
	ThreeDObject newObject;
	Matrix rotationMatrix(1, 1);
	switch (axis)
	{
	case 'X':
		rotationMatrix = getRotationMatrixXAxis(degrees);
		break;
	case 'Y':
		rotationMatrix = getRotationMatrixYAxis(degrees);
		break;
	case 'Z':
		rotationMatrix = getRotationMatrixZAxis(degrees);
		break;
	default:
		break;
	}

	//Rotate
	for (int i = 0; i < newObject.points.size(); i++)
	{
		newObject.points[i] = rotationMatrix * object.points[i];
	}

	return newObject;
}

ThreeDObject ExpanseHelper::translateMatrix(ThreeDObject& object, double xChange, double yChange, double zChange) {
	ThreeDObject newObject;
	Matrix translationMatrix = getTranslationMatrix(xChange, yChange, zChange);

	newObject.centerPoint = translationMatrix * object.centerPoint;
	for (int i = 0; i < newObject.points.size(); i++)
	{
		newObject.points[i] = translationMatrix * object.points[i];
	}
	return newObject;
}

