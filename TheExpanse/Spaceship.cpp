#include "Spaceship.h"

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

	//front triangle
	lines.push_back({ points[8], points[9] });
	lines.push_back({ points[9], points[10] });
	lines.push_back({ points[10], points[11] });
	lines.push_back({ points[11], points[8] });

	lines.push_back({ points[12], points[13] });
	lines.push_back({ points[13], points[14] });
	lines.push_back({ points[14], points[15] });
	lines.push_back({ points[15], points[12] });

	lines.push_back({ points[8], points[12] });
	lines.push_back({ points[9], points[13] });
	lines.push_back({ points[10], points[14] });
	lines.push_back({ points[11], points[15] });

	//left wing 16-23
	lines.push_back({ points[16], points[17] });
	lines.push_back({ points[17], points[18] });
	lines.push_back({ points[18], points[19] });
	lines.push_back({ points[19], points[16] });

	lines.push_back({ points[22], points[23] });

	lines.push_back({ points[16], points[23] });
	lines.push_back({ points[17], points[22] });
	lines.push_back({ points[18], points[22] });
	lines.push_back({ points[19], points[23] });

	//right wing 24-31
	lines.push_back({ points[24], points[25] });
	lines.push_back({ points[25], points[26] });
	lines.push_back({ points[26], points[27] });
	lines.push_back({ points[27], points[24] });

	lines.push_back({ points[30], points[31] });

	lines.push_back({ points[24], points[31] });
	lines.push_back({ points[25], points[30] });
	lines.push_back({ points[26], points[30] });
	lines.push_back({ points[27], points[31] });

	centerPoint = Vector(2, 2, -4.5);
}
