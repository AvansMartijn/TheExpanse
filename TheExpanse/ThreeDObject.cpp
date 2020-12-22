#include "ThreeDObject.h"

ThreeDObject::ThreeDObject()
{
	points.push_back({ -1, -1, 0 });
	points.push_back({ -1, 1, 0 });
	points.push_back({ 1, 1, 0 });
	points.push_back({ 1, -1, 0 });


	// BOX
	/*lines.push_back({ { -1, -1, 0 }, {-1, 1, 0 } });
	lines.push_back({ { -1, 1, 0 }, {1, 1, 0 } });
	lines.push_back({ { 1, 1, 0 }, {1, -1, 0 } });
	lines.push_back({ { 1, -1, 0 }, {-1, -1, 0 } });*/

	//CHIEL
	lines.push_back({ { 1, 1, 1 }, {1, 2, 1 } });
	lines.push_back({ { 1, 2, 1 }, {2, 2, 1 } });
	lines.push_back({ { 2, 2, 1 }, {2, 1, 1 } });
	lines.push_back({ { 2, 1, 1 }, {1, 1, 1 } });

	lines.push_back({ { 1, 1, 2 }, {1, 2, 2 } });
	lines.push_back({ { 1, 2, 2 }, {2, 2, 2 } });
	lines.push_back({ { 2, 2, 2 }, {2, 1, 2 } });
	lines.push_back({ { 2, 1, 2 }, {1, 1, 2 } });

	lines.push_back({ { 1, 1, 1 }, {1, 1, 2 } });
	lines.push_back({ { 1, 2, 1 }, {1, 2, 2 } });
	lines.push_back({ { 2, 2, 1 }, {2, 2, 2 } });
	lines.push_back({ { 2, 1, 1 }, {2, 1, 2 } });

	// STAR
	/*lines.push_back({ { 4, 4 }, { 0, 4 } });
	lines.push_back({ { 0, 4 }, { 3.5, 1 } });
	lines.push_back({ { 3.5, 1 }, { 2, 6 } });
	lines.push_back({ { 2, 6 }, { 0.5, 1 } });
	lines.push_back({ { 0.5, 1 }, { 4, 4 } });*/
}

Vector ThreeDObject::getCenter()
{
	return { 1.5, 1.5, 1.5 };
}
