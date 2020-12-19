#include "TwoDObject.h"

TwoDObject::TwoDObject()
{
	/*points.push_back({ 1, 1 });
	points.push_back({ 2, 1 });
	points.push_back({ 1, 2 });
	points.push_back({ 2, 2 });*/


	// BOX
	lines.push_back({ { 1, 1 }, { 1, 2 } });
	lines.push_back({ { 1, 2 }, {2, 2 } });
	lines.push_back({ { 2, 2 }, {2, 1 } });
	lines.push_back({ { 2, 1 }, {1, 1 } });

	// STAR
	/*lines.push_back({ { 4, 4 }, { 0, 4 } });
	lines.push_back({ { 0, 4 }, { 3.5, 1 } });
	lines.push_back({ { 3.5, 1 }, { 2, 6 } });
	lines.push_back({ { 2, 6 }, { 0.5, 1 } });
	lines.push_back({ { 0.5, 1 }, { 4, 4 } });*/
}

std::tuple<double, double> TwoDObject::getCenter()
{
	/*int hightestX;
	int lowestX;

	int hightestY;
	int lowestX;
	for (int i = 0; i < points.size(); i++)
	{
		const std::tuple<int, int> coordinate = points[i];

		
	}*/


	std::tuple<double, double> centroid = { 0, 0 };
	double signedArea = 0.0;
	double x0 = 0.0; // Current vertex X
	double y0 = 0.0; // Current vertex Y
	double x1 = 0.0; // Next vertex X
	double y1 = 0.0; // Next vertex Y
	double a = 0.0;  // Partial signed area

	// For all vertices
	int i = 0;
	for (i = 0; i < lines.size(); ++i)
	{
		x0 = (std::get<0>(lines[i])).x;
		y0 = (std::get<0>(lines[i])).y;
		x1 = (std::get<1>(lines[i])).x;
		y1 = (std::get<1>(lines[i])).y;
		a = x0 * y1 - x1 * y0;
		signedArea += a;
		double centroidX = std::get<0>(centroid) + (x0 + x1) * a;
		double centroidY = std::get<1>(centroid) + (y0 + y1) * a;
		centroid = { centroidX, centroidY };
	}

	signedArea *= 0.5;

	double centroidX = std::get<0>(centroid) / (6.0 * signedArea);
	double centroidY = std::get<1>(centroid) / (6.0 * signedArea);
	centroid = { centroidX, centroidY };
	return centroid;

	//return std::tuple<double, double>({1.5, 1.5});
}
