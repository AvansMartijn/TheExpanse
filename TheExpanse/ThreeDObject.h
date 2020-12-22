#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Line.h"

class ThreeDObject
{
public:
	ThreeDObject();
	std::vector<Vector> points;
	std::vector<Line> lines;
	Vector getCenter();
};

