#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Vertice.h"
#include "PulseData.h"

class ThreeDObject
{
public:
	//ThreeDObject();
	std::vector<Vector> points;
	Vector centerPoint;
	Vector up;
	Vector right;
	Vector forward;
	std::vector<Vertice> lines;
	PulseData pulseData;
	Vector velocity;
	int moveCounter;

};

