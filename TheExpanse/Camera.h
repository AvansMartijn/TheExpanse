
#pragma once
#include "Vector.h"
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

};

