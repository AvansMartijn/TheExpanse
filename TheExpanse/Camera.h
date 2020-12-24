
#pragma once
#include "Vector.h"
#include "ThreeDObject.h"
#include "ExpanseHelper.h"

class Camera
{
public:
	Camera();
	Vector eye;
	Vector lookAt;
	Vector direction;
	Vector up;
	Vector right;
	double fovY;
	double far;
	double near;

	ThreeDObject createPerspective(const ThreeDObject& object);

private:
	ExpanseHelper helper;

};

