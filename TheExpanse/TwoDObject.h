#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"
#include "Line.h"

class TwoDObject
{
public:
	TwoDObject();
	std::vector<Line> lines;
	Vector getCenter();
};

