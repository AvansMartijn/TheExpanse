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

ThreeDObject ExpanseHelper::scaleOnLocation(const ThreeDObject& object, double xScale, double yScale, double zScale)
{
	ThreeDObject newObject = object;
	Matrix translationMatrixToOrigin = getTranslationMatrix(-object.centerPoint.x, -object.centerPoint.y, -object.centerPoint.z);
	Matrix translationMatrixBack = getTranslationMatrix(object.centerPoint.x, object.centerPoint.y, object.centerPoint.z);
	Matrix scalingMatrix = getScalingMatrix(xScale, yScale, zScale);

	Matrix superMatrix = translationMatrixBack * scalingMatrix * translationMatrixToOrigin;

	//Scaling around centerpoint does not change centerpoint
	newObject.forward = superMatrix * object.forward;
	newObject.up = superMatrix * object.up;
	newObject.right = superMatrix * object.right;
	for (int i = 0; i < newObject.points.size(); i++)
	{
		newObject.points[i] = superMatrix * object.points[i];
	}
	newObject.calculateAABB();

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

ThreeDObject ExpanseHelper::rotate(const ThreeDObject& object, double degrees, char axis)
{
	ThreeDObject newObject = object;

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
	//Rotating around centerpoint does not change centerpoint
	newObject.forward = superMatrix * object.forward;
	newObject.up = superMatrix * object.up;
	newObject.right = superMatrix * object.right;
	for (int i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = superMatrix * object.points[i];
	}

	return newObject;
}

ThreeDObject ExpanseHelper::rotateAroundOrigin(const ThreeDObject& object, double degrees, char axis)
{
	ThreeDObject newObject = object;
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
	newObject.forward = rotationMatrix * object.forward;
	newObject.up = rotationMatrix * object.up;
	newObject.right = rotationMatrix * object.right;
	newObject.centerPoint = rotationMatrix * object.centerPoint;
	for (int i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = rotationMatrix * object.points[i];
	}

	return newObject;
}

ThreeDObject ExpanseHelper::translateMatrix(const ThreeDObject& object, double xChange, double yChange, double zChange) {
	ThreeDObject newObject = object;
	Matrix translationMatrix = getTranslationMatrix(xChange, yChange, zChange);

	newObject.centerPoint = translationMatrix * object.centerPoint;
	newObject.forward = translationMatrix * object.forward;
	newObject.up = translationMatrix * object.up;
	newObject.right = translationMatrix * object.right;
	for (int i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = translationMatrix * object.points[i];
	}
	newObject.calculateAABB();
	return newObject;
}

Vector ExpanseHelper::getCrossProduct(const Vector& vA, const Vector& vB) {
	Vector v;
	v.x = vA.y * vB.z - vA.z * vB.y;
	v.y = vA.z * vB.x - vA.x * vB.z;
	v.z = vA.x * vB.y - vA.y * vB.x;

	return v;
}

Vector ExpanseHelper::normalize(const Vector& v) {
	double length = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	Vector newVector;
	if (length != 0.)
	{
		newVector.x = v.x / length;
		newVector.y = v.y / length;
		newVector.z = v.z / length;
	}

	return newVector;
}

Vector ExpanseHelper::getPerpendicularVector(const Vector& s, const Vector& r)
{
	double lambda;
	Vector perpVector;


	//perpVector = s + (r * lambda);

	return perpVector;
}

ThreeDObject ExpanseHelper::roll(const ThreeDObject& object, double degrees)
{
	ThreeDObject newObject = object;

	Vector cp = object.centerPoint;
	Vector up = object.forward;

	Vector v = cp - up;

	Matrix rollRotationMatrix = getRollRotationMatrix(object, degrees, v);

	//Roll Around centerpoint and Forward does not change it.
	//newObject.forward = rollRotationMatrix * object.forward;
	newObject.up = rollRotationMatrix * object.up;
	newObject.right = rollRotationMatrix * object.right;
	for (size_t i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = rollRotationMatrix * object.points[i];
	}
	newObject.calculateAABB();
	return newObject;
}

ThreeDObject ExpanseHelper::jaw(const ThreeDObject& object, double degrees)
{
	ThreeDObject newObject = object;

	Vector cp = object.centerPoint;
	Vector up = object.up;

	Vector v = cp - up;

	Matrix rollRotationMatrix = getRollRotationMatrix(object, degrees, v);

	//Roll Around centerpoint and up does not change it.
	//newObject.up = rollRotationMatrix * object.up;
	newObject.forward = rollRotationMatrix * object.forward;
	newObject.right = rollRotationMatrix * object.right;
	for (size_t i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = rollRotationMatrix * object.points[i];
	}
	newObject.calculateAABB();

	return newObject;
}

ThreeDObject ExpanseHelper::pitch(const ThreeDObject& object, double degrees)
{
	ThreeDObject newObject = object;

	Vector cp = object.centerPoint;
	Vector up = object.right;

	Vector v = cp - up;

	Matrix rollRotationMatrix = getRollRotationMatrix(object, degrees, v);

	//Roll Around centerpoint and right does not change it.
	//newObject.right = rollRotationMatrix * object.right;
	newObject.forward = rollRotationMatrix * object.forward;
	newObject.up = rollRotationMatrix * object.up;
	for (size_t i = 0; i < object.points.size(); i++)
	{
		newObject.points[i] = rollRotationMatrix * object.points[i];
	}
	newObject.calculateAABB();

	return newObject;
}

Matrix ExpanseHelper::getRollRotationMatrix(const ThreeDObject& object, double degrees, const Vector& vec)
{
	//STEP ONE: Rotate to XY
	Vector v = vec;
	//if both are 0, turn it ever so slightly to prevent undefined behaviour
	if (v.x == 0 && v.z == 0) {
		v.x = 0.00000000000001;
		v.z = 0.00000000000001;
	}
	//1.1 Get Tau1 (Angle between X-axis and bottom of triangle
	Matrix yRotationMatrix(4, 4);

	yRotationMatrix.mData[0] = {
		v.x / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0,
		v.z / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0
	};
	yRotationMatrix.mData[1] = {
		0, 1, 0, 0
	};
	yRotationMatrix.mData[2] = {
		-v.z / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0,
		v.x / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0
	};
	yRotationMatrix.mData[3] = {
		0, 0, 0, 1
	};

	//STEP FIVE
	Matrix yRotationMatrixBack(4, 4);
	yRotationMatrixBack.mData[0] = {
		v.x / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0,
		-v.z / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0
	};
	yRotationMatrixBack.mData[1] = {
		0, 1, 0, 0
	};
	yRotationMatrixBack.mData[2] = {
		v.z / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0,
		v.x / sqrt(pow(v.x, 2) + pow(v.z, 2)),
		0
	};
	yRotationMatrixBack.mData[3] = {
		0, 0, 0, 1
	};


	//STEP TWO: ROTATE TO X
	Matrix zRotationMatrix(4, 4);
	zRotationMatrix.mData[0] = {
		sqrt(pow(v.x, 2) + pow(v.z, 2)) / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		v.y / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		0, 0
	};
	zRotationMatrix.mData[1] = {
		-v.y / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		sqrt(pow(v.x, 2) + pow(v.z, 2)) / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		0, 0
	};
	zRotationMatrix.mData[2] = {
		0, 0, 1, 0
	};
	zRotationMatrix.mData[3] = {
		0, 0, 0, 1
	};


	//STEP QUATTRO: GET Mirror for returning
	Matrix zRotationMatrixBack(4, 4);
	zRotationMatrixBack.mData[0] = {
		sqrt(pow(v.x, 2) + pow(v.z, 2)) / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		-v.y / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		0, 0
	};
	zRotationMatrixBack.mData[1] = {
		v.y / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		sqrt(pow(v.x, 2) + pow(v.z, 2)) / sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)),
		0, 0
	};
	zRotationMatrixBack.mData[2] = {
		0, 0, 1, 0
	};
	zRotationMatrixBack.mData[3] = {
		0, 0, 0, 1
	};



	//STEP TRES: Rotate around X Axis
	Matrix xRotationMatrix = getRotationMatrixXAxis(degrees);


	//Translations
	Matrix toOrigin = getTranslationMatrix(-object.centerPoint.x, -object.centerPoint.y, -object.centerPoint.z);
	Matrix back = getTranslationMatrix(object.centerPoint.x, object.centerPoint.y, object.centerPoint.z);
	Matrix final = back * yRotationMatrixBack * zRotationMatrixBack * xRotationMatrix * zRotationMatrix * yRotationMatrix * toOrigin;

	return final;
}



Matrix ExpanseHelper::getInverseTransformationMatrix(const Vector& right, const Vector& up, const Vector& direction) {
	Matrix inverseTransformMatrix(4, 4);
	inverseTransformMatrix.mData[0] = { right.x, right.y, right.z, 0 };
	inverseTransformMatrix.mData[1] = { up.x, up.y, up.z, 0 };
	inverseTransformMatrix.mData[2] = { direction.x, direction.y, direction.z, 0 };
	inverseTransformMatrix.mData[3] = {	0, 0, 0, 1};

	return inverseTransformMatrix;
}

Matrix ExpanseHelper::getProjectionMatrix(double near, double far, double fovY)
{
	Matrix projectionMatrix(4, 4);
	double scale = near * tan((fovY/2) * (PI / 180.0));

	projectionMatrix.mData[0] = { scale, 0, 0, 0 };
	projectionMatrix.mData[1] = { 0, scale, 0, 0 };
	projectionMatrix.mData[2] = { 0, 0, (-far/(far-near)), -1 };
	projectionMatrix.mData[3] = { 0, 0, (-far*near/(far-near)), 0 };

	return projectionMatrix;
}

Vector ExpanseHelper::correctProjection(const Vector& vector, double screenSizeX, double screenSizeY)
{
	
	Vector v;
	v.x = (screenSizeX / 2) + (vector.x / vector.w) * (screenSizeX / 2);
	v.y = (screenSizeY / 2) + (vector.y / vector.w) * (screenSizeY / 2);
	v.z = vector.z;
	v.w = vector.w;
	
	return v;
}

ThreeDObject ExpanseHelper::pulseObject(const ThreeDObject& object)
{
	ThreeDObject newObj;
	PulseData pulseData = object.pulseData;
	if (pulseData.growTimes > 0) {
		if (pulseData.isGrowing) {
			newObj = scaleOnLocation(object, pulseData.growMultiplier, pulseData.growMultiplier, pulseData.growMultiplier);
			pulseData.growCounter++;
			if (pulseData.growCounter >= pulseData.growTimes) {
				pulseData.isGrowing = false;
			}
			newObj.pulseData = pulseData;
			return newObj;
		}
		else {
			newObj = scaleOnLocation(object,1 /pulseData.growMultiplier, 1 / pulseData.growMultiplier, 1 / pulseData.growMultiplier);
			pulseData.growCounter--;
			if (pulseData.growCounter <= 0) {
				pulseData.isGrowing = true;
			}
			newObj.pulseData = pulseData;
			return newObj;
		}
	}
	return object;
}

Vector ExpanseHelper::getForwardVector(const ThreeDObject& object)
{
	
	/*ThreeDObject obj;
	obj.points = object.points;
	obj.lines = object.lines;
	Vector right = obj.points[pointAIndex] - obj.points[pointBIndex];
	Vector up = obj.points[pointAIndex] - obj.points[pointCIndex];*/

	//return getCrossProduct(right, up);
	Vector fw = object.forward;
	Vector cp = object.centerPoint;
	return fw - cp;
}

AABB ExpanseHelper::findAABB(const ThreeDObject& object) {
	Vector min = object.centerPoint;
	Vector max = object.centerPoint;
	for (const Vector& point : object.points) {
		
		if (point.x < min.x) {
			min.x = point.x;
		}
		if (point.y < min.y) {
			min.y = point.y;
		}
		if (point.z < min.z) {
			min.z = point.z;
		}

		if (point.x > max.x) {
			max.x = point.x;
		}
		if (point.y > max.y) {
			max.y = point.y;
		}
		if (point.z > max.z) {
			max.z = point.z;
		}
	}

	return { min, max };
}

bool ExpanseHelper::intersects(AABB a,AABB b) {
	return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		(a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		(a.min.z <= b.max.z && a.max.z >= b.min.z);
}




