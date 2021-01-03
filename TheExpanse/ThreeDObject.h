#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Vertice.h"
#include "PulseData.h"
#include "AABB.h"

class ThreeDObject
{
public:
	std::vector<Vector> points;
	Vector centerPoint;
	Vector up;
	Vector right;
	Vector forward;
	std::vector<Vertice> lines;
	PulseData pulseData;
	Vector velocity;
	int moveCounter;
	AABB AABB;
	void calculateAABB();
	
	


};

