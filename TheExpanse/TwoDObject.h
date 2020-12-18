#pragma once
#include <tuple>
#include <vector>
#include "Vector.h"

class TwoDObject
{
public:
	TwoDObject();
	std::vector<std::tuple<int, int>> points;
	std::vector<std::tuple<Vector, Vector>> lines;
};

