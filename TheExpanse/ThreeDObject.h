#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Vertice.h"

class ThreeDObject
{
public:
	//ThreeDObject();
	std::vector<Vector> points;
	Vector centerPoint;
	std::vector<Vertice> lines;
};

