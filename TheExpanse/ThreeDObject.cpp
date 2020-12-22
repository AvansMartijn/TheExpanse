#include "ThreeDObject.h"

ThreeDObject::ThreeDObject()
{
	points.push_back({ 1, 1, 1 });
	points.push_back({ 1, 3, 1 });
	points.push_back({ 3, 3, 1 });
	points.push_back({ 3, 1, 1 });

	points.push_back({ 1, 1, 3 });
	points.push_back({ 1, 3, 3 });
	points.push_back({ 3, 3, 3 });
	points.push_back({ 3, 1, 3 });


	// BOX
	/*lines.push_back({ { -1, -1, 0 }, {-1, 1, 0 } });
	lines.push_back({ { -1, 1, 0 }, {1, 1, 0 } });
	lines.push_back({ { 1, 1, 0 }, {1, -1, 0 } });
	lines.push_back({ { 1, -1, 0 }, {-1, -1, 0 } });*/

	//CHIEL
	lines.push_back({ points[0], points[1] });
	lines.push_back({ points[1], points[2] });
	lines.push_back({ points[2], points[3] });
	lines.push_back({ points[3], points[0] });

	lines.push_back({ points[4], points[5] });
	lines.push_back({ points[5], points[6] });
	lines.push_back({ points[6], points[7] });
	lines.push_back({ points[7], points[4] });

	lines.push_back({ points[0], points[4] });
	lines.push_back({ points[1], points[5] });
	lines.push_back({ points[2], points[6] });
	lines.push_back({ points[3], points[7] });

	centerPoint = Vector( 2, 2, 2 );

	// STAR
	/*lines.push_back({ { 4, 4 }, { 0, 4 } });
	lines.push_back({ { 0, 4 }, { 3.5, 1 } });
	lines.push_back({ { 3.5, 1 }, { 2, 6 } });
	lines.push_back({ { 2, 6 }, { 0.5, 1 } });
	lines.push_back({ { 0.5, 1 }, { 4, 4 } });*/
}