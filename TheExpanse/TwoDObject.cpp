#include "TwoDObject.h"

TwoDObject::TwoDObject()
{
	/*points.push_back({ 1, 1 });
	points.push_back({ 2, 1 });
	points.push_back({ 1, 2 });
	points.push_back({ 2, 2 });*/


	// BOX
	/*lines.push_back({ { 1, 1, 1 }, { 1, 2, 1 } });
	lines.push_back({ { 1, 2, 1 }, {2, 2, 1 } });
	lines.push_back({ { 2, 2, 1 }, {2, 1, 1 } });
	lines.push_back({ { 2, 1, 1 }, {1, 1, 1 } });*/

	// STAR
	/*lines.push_back({ { 4, 4 }, { 0, 4 } });
	lines.push_back({ { 0, 4 }, { 3.5, 1 } });
	lines.push_back({ { 3.5, 1 }, { 2, 6 } });
	lines.push_back({ { 2, 6 }, { 0.5, 1 } });
	lines.push_back({ { 0.5, 1 }, { 4, 4 } });*/
}

Vector TwoDObject::getCenter()
{
	Vector centroid = { 0, 0, 1 };
	double signedArea = 0.0;
	double x0 = 0.0; // Current vertex X
	double y0 = 0.0; // Current vertex Y
	double x1 = 0.0; // Next vertex X
	double y1 = 0.0; // Next vertex Y
	double a = 0.0;  // Partial signed area

	// For all vertices
	int i = 0;

	signedArea *= 0.5;

	double centroidX = centroid.x / (6.0 * signedArea);
	double centroidY = centroid.y / (6.0 * signedArea);
	centroid = { centroidX, centroidY, 1 };
	return centroid;
}
