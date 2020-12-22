#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Vertice.h"

class ThreeDObject
{
public:
	ThreeDObject();
	std::vector<Vector> points;
	std::vector<Vertice> lines;
	Vector getCenter();
};

