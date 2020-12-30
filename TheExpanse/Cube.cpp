#include "Cube.h"

Cube::Cube()
{
	//BOX <-----------------------------------
	points.push_back({ 1, 1, -1 });
	points.push_back({ 1, 3, -1 });
	points.push_back({ 3, 3, -1 });
	points.push_back({ 3, 1, -1 });

	points.push_back({ 1, 1, -3 });
	points.push_back({ 1, 3, -3 });
	points.push_back({ 3, 3, -3 });
	points.push_back({ 3, 1, -3 });

	//BOX
	lines.push_back({ 0, 1 });
	lines.push_back({ 1, 2 });
	lines.push_back({ 2, 3 });
	lines.push_back({ 3, 0 });

	lines.push_back({ 4, 5 });
	lines.push_back({ 5, 6 });
	lines.push_back({ 6, 7 });
	lines.push_back({ 7, 4 });

	lines.push_back({ 0, 4 });
	lines.push_back({ 1, 5 });
	lines.push_back({ 2, 6 });
	lines.push_back({ 3, 7 });

	centerPoint = Vector( 2, 2, -2 );
	forward = {2, 2, -3};
	up = {2, 3, -2};
	right = { 3, 2, -2 };
	velocity = {0,0,0};
	moveCounter = 0;
	calculateAABB();
	
}
