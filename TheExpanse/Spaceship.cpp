#include "Spaceship.h"
#include "ExpanseHelper.h"

Spaceship::Spaceship()
{
	////custom
	//body
	points.push_back({ 1, 1, -1 });
	points.push_back({ 1, 3, -1 });
	points.push_back({ 3, 3, -1 });
	points.push_back({ 3, 1, -1 });

	points.push_back({ 1, 1, -8 });
	points.push_back({ 1, 3, -8 });
	points.push_back({ 3, 3, -8 });
	points.push_back({ 3, 1, -8 });

	//front
	points.push_back({ 1, 1, -8 });//8
	points.push_back({ 1, 3, -8 });//9
	points.push_back({ 3, 3, -8 });//10
	points.push_back({ 3, 1, -8 });//11

	points.push_back({ 1.5, 1.5, -9 });//12 
	points.push_back({ 1.5, 2.5, -9 });//13
	points.push_back({ 2.5, 2.5, -9 });//14
	points.push_back({ 2.5, 1.5, -9 });//15

	//left wing
	points.push_back({ 0, 1.4, -2 });//16
	points.push_back({ 0, 1.5, -2 });//17
	points.push_back({ 1, 1.5, -2 });//18
	points.push_back({ 1, 1.4, -2 });//19

	points.push_back({ 0, 1.4, -7 });//20
	points.push_back({ 0, 1.5, -7 });//21
	points.push_back({ 1, 1.5, -7 });//22
	points.push_back({ 1, 1.4, -7 });//23

	//right wing
	points.push_back({ 3, 1.4, -2 });//24
	points.push_back({ 3, 1.5, -2 });//25
	points.push_back({ 4, 1.5, -2 });//26
	points.push_back({ 4, 1.4, -2 });//27

	points.push_back({ 3, 1.4, -7 });//28
	points.push_back({ 3, 1.5, -7 });//29
	points.push_back({ 3, 1.5, -7 });//30
	points.push_back({ 3, 1.4, -7 });//31

	//body
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

	//front triangle
	lines.push_back({ 8, 9 });
	lines.push_back({ 9, 10 });
	lines.push_back({ 10, 11 });
	lines.push_back({ 11, 8 });

	lines.push_back({ 12, 13 });
	lines.push_back({ 13, 14 });
	lines.push_back({ 14, 15 });
	lines.push_back({ 15, 12 });

	lines.push_back({ 8, 12 });
	lines.push_back({ 9, 13 });
	lines.push_back({ 10, 14 });
	lines.push_back({ 11, 15 });

	//left wing 16-23
	lines.push_back({ 16, 17 });
	lines.push_back({ 17, 18 });
	lines.push_back({ 18, 19 });
	lines.push_back({ 19, 16 });

	lines.push_back({ 22, 23 });

	lines.push_back({ 16, 23 });
	lines.push_back({ 17, 22 });
	lines.push_back({ 18, 22 });
	lines.push_back({ 19, 23 });

	//right wing 24-31
	lines.push_back({ 24, 25 });
	lines.push_back({ 25, 26 });
	lines.push_back({ 26, 27 });
	lines.push_back({ 27, 24 });

	lines.push_back({ 30, 31 });

	lines.push_back({ 24, 31 });
	lines.push_back({ 25, 30 });
	lines.push_back({ 26, 30 });
	lines.push_back({ 27, 31 });

	centerPoint = Vector(2, 2, -4.5);
	right = { 3,2,-4.5 };
	forward = { 2,2, -5.5 };
	up = { 2,3,-4.5 };
}


