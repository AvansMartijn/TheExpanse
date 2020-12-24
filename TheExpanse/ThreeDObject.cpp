#include "ThreeDObject.h"

ThreeDObject::ThreeDObject()
{
	//BOX
	points.push_back({ 1, 1, -1 });
	points.push_back({ 1, 5, -1 });
	points.push_back({ 5, 5, -1 });
	points.push_back({ 5, 1, -1 });

	points.push_back({ 1, 1, -3 });
	points.push_back({ 1, 5, -3 });
	points.push_back({ 5, 5, -3 });
	points.push_back({ 5, 1, -3 });

	//BOX
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

	centerPoint = Vector( 2, 3, 2 );

	////TOP
	//points.push_back({ 6, 1, -5 }); //0
	//points.push_back({ 7, 1, -5 }); //1
	//lines.push_back({ points[0], points[1] });
	//points.push_back({ 4, 2, -5 }); //2
	//points.push_back({ 9, 2, -5 }); //3
	//lines.push_back({ points[0], points[2] });
	//lines.push_back({ points[1], points[3] });
	//points.push_back({ 1, 6, -5 }); //4
	//points.push_back({ 12, 6, -5 }); //5
	//lines.push_back({ points[2], points[4] });
	//lines.push_back({ points[3], points[5] });

	////BODY
	//points.push_back({ 1, 22, -5 }); //6
	//points.push_back({ 12, 22, -5 }); //7

	//lines.push_back({ points[4], points[6] });
	//lines.push_back({ points[5], points[7] });

	////TAIL
	//points.push_back({ 3, 24, -5 }); //8
	//points.push_back({ 10, 24, -5 }); //9

	//lines.push_back({ points[6], points[8] });
	//lines.push_back({ points[7], points[9] });
	//points.push_back({ 2, 24, -5 }); //10
	//points.push_back({ 11, 24, -5 }); //11
	//lines.push_back({ points[8], points[10] });
	//lines.push_back({ points[9], points[11] });
	//points.push_back({ 1, 26, -5 }); //12
	//points.push_back({ 12, 26, -5 }); //13
	//lines.push_back({ points[10], points[12] });
	//lines.push_back({ points[11], points[13] });

	////Thick
	////TOP
	//points.push_back({ 6, 1, -11 }); //14
	//points.push_back({ 7, 1, -11 }); //15
	//lines.push_back({ points[14], points[15] });
	//lines.push_back({ points[0], points[14] });
	//lines.push_back({ points[1], points[15] });
	//points.push_back({ 4, 2, -11 }); //16
	//points.push_back({ 9, 2, -11 }); //17
	//lines.push_back({ points[14], points[16] });
	//lines.push_back({ points[15], points[17] });
	//lines.push_back({ points[2], points[16] });
	//lines.push_back({ points[3], points[17] });
	//points.push_back({ 1, 6, -11 }); //18
	//points.push_back({ 12, 6, -11 }); //19
	//lines.push_back({ points[16], points[18] });
	//lines.push_back({ points[17], points[19] });
	//lines.push_back({ points[4], points[18] });
	//lines.push_back({ points[5], points[19] });

	////BODY
	//points.push_back({ 1, 22, -11 }); //20
	//points.push_back({ 12, 22, -11 }); //21
	//lines.push_back({ points[18], points[20] });
	//lines.push_back({ points[19], points[21] });
	//lines.push_back({ points[6], points[20] });
	//lines.push_back({ points[7], points[21] });

	////TAIL
	//points.push_back({ 3, 24, -11 }); //22
	//points.push_back({ 9, 24, -11 }); //23
	//lines.push_back({ points[20], points[22] });
	//lines.push_back({ points[21], points[23] });
	//lines.push_back({ points[8], points[22] });
	//lines.push_back({ points[9], points[23] });
	//points.push_back({ 2, 24, -11 }); //24
	//points.push_back({ 11, 24, -11 }); //25
	//lines.push_back({ points[22], points[24] });
	//lines.push_back({ points[23], points[25] });
	//lines.push_back({ points[10], points[24] });
	//lines.push_back({ points[11], points[25] });
	//points.push_back({ 1, 26, -11 }); //26
	//points.push_back({ 12, 26, -11 }); //27
	//lines.push_back({ points[24], points[26] });
	//lines.push_back({ points[25], points[27] });
	//lines.push_back({ points[12], points[26] });
	//lines.push_back({ points[13], points[27] });

	//centerPoint = Vector(5, 12.5, -7);

	
}