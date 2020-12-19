#include "TwoDObject.h"

TwoDObject::TwoDObject()
{
	points.push_back({ 1, 1 });
	points.push_back({ 2, 1 });
	points.push_back({ 1, 2 });
	points.push_back({ 2, 2 });


	// BOX
	lines.push_back({ { 1, 1 }, { 1, 2 } });
	lines.push_back({ { 1, 2 }, {2, 2 } });
	lines.push_back({ { 2, 2 }, {2, 1 } });
	lines.push_back({ { 2, 1 }, {1, 1 } });

	// STAR
	/*lines.push_back({ { 6.5, 0 }, { 9, 5 } });
	lines.push_back({ { 9, 5 }, {14, 5.5 } });
	lines.push_back({ { 14, 5.5 }, {10.5, 9 } });
	lines.push_back({ { 10.5, 9 }, {12, 14 } });
	lines.push_back({ { 12, 14 }, {6.5, 11.5 } });
	lines.push_back({ { 6.5, 11.5 }, {2, 14 } });
	lines.push_back({ { 2, 14 }, {3.5, 9 } });
	lines.push_back({ { 3.5, 9 }, {0, 5.5 } });
	lines.push_back({ { 0, 5.5 }, {5, 5 } });
	lines.push_back({ { 5, 5 }, {6.5, 0 } });*/
}

std::tuple<int, int> TwoDObject::getCenter()
{
	/*int hightestX;
	int lowestX;

	int hightestY;
	int lowestX;
	for (int i = 0; i < points.size(); i++)
	{
		const std::tuple<int, int> coordinate = points[i];

		
	}*/
	return std::tuple<int, int>({});
}
