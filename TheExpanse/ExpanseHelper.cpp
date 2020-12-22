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
	Vector center = object.getCenter();
	Matrix translationMatrixToOrigin = getTranslationMatrix(-center.x, -center.y, 1);
	Matrix translationMatrixBack = getTranslationMatrix(center.x, center.y, 1);
	Matrix scalingMatrix = getScalingMatrix(xScale, yScale, zScale);

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

Matrix ExpanseHelper::getRotationMatrixZAxis(double degrees)
{
	Matrix rotationMatrix(4, 4);
	double PI = 3.14159265358979323846264338327950288419;

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
	double PI = 3.14159265358979323846264338327950288419;

	rotationMatrix.mData[0][0] = -sin(degrees * PI / 180.0);
	rotationMatrix.mData[0][1] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[0][2] = 0;
	rotationMatrix.mData[0][3] = 0;

	rotationMatrix.mData[1][0] = 0;
	rotationMatrix.mData[1][1] = 0;
	rotationMatrix.mData[1][2] = 1;
	rotationMatrix.mData[1][3] = 0;

	rotationMatrix.mData[2][0] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[2][1] = sin(degrees * PI / 180.0);
	rotationMatrix.mData[2][2] = 0;
	rotationMatrix.mData[2][3] = 0;

	rotationMatrix.mData[3][0] = 0;
	rotationMatrix.mData[3][1] = 0;
	rotationMatrix.mData[3][2] = 0;
	rotationMatrix.mData[3][3] = 1;

	return rotationMatrix;
}
Matrix ExpanseHelper::getRotationMatrixXAxis(double degrees)
{
	Matrix rotationMatrix(4, 4);
	double PI = 3.14159265358979323846264338327950288419;

	rotationMatrix.mData[0][0] = 0;
	rotationMatrix.mData[0][1] = 0;
	rotationMatrix.mData[0][2] = 1;
	rotationMatrix.mData[0][3] = 0;

	rotationMatrix.mData[1][0] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[1][1] = sin(degrees * PI / 180.0);
	rotationMatrix.mData[1][2] = 0;
	rotationMatrix.mData[1][3] = 0;

	rotationMatrix.mData[2][0] = -sin(degrees * PI / 180.0);
	rotationMatrix.mData[2][1] = cos(degrees * PI / 180.0);
	rotationMatrix.mData[2][2] = 0;
	rotationMatrix.mData[2][3] = 0;

	rotationMatrix.mData[3][0] = 0;
	rotationMatrix.mData[3][1] = 0;
	rotationMatrix.mData[3][2] = 0;
	rotationMatrix.mData[3][3] = 1;

	return rotationMatrix;
}

ThreeDObject ExpanseHelper::rotate(ThreeDObject& object, double degrees, char axis)
{
	ThreeDObject newObject;
	Vector center = object.getCenter();
	Matrix translationMatrixToOrigin = getTranslationMatrix(-center.x, -center.y, 1);
	Matrix translationMatrixBack = getTranslationMatrix(center.x, center.y, 1);
	Matrix rotationMatrix(1,1);
	switch (axis)
	{
	case 'X':
		rotationMatrix = getRotationMatrixXAxis(degrees);
	case 'Y':
		rotationMatrix = getRotationMatrixYAxis(degrees);
	case 'Z':
		rotationMatrix = getRotationMatrixZAxis(degrees);
	default:
		break;
	}

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
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { rotationMatrix * object.lines[i].start, rotationMatrix * object.lines[i].end };
	}

	return newObject;
}

ThreeDObject ExpanseHelper::translateMatrix(ThreeDObject& object, double xChange, double yChange, double zChange) {
	ThreeDObject newObject;
	Matrix translationMatrix = getTranslationMatrix(xChange, yChange, zChange);
	for (int i = 0; i < newObject.lines.size(); i++)
	{
		newObject.lines[i] = { translationMatrix * object.lines[i].start, translationMatrix * object.lines[i].end };
	}
	return newObject;
}

