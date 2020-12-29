#include "ThreeDObject.h";
#include "Vector.h";

#pragma once
class Spaceship: public ThreeDObject
{
public:
	Spaceship();
	Vector getForward();
};

