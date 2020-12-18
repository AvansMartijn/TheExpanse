#include "TwoDObject.h"

TwoDObject::TwoDObject()
{
	/*points.push_back({ 1, 1 });
	points.push_back({ 2, 1 });
	points.push_back({ 1, 2 });
	points.push_back({ 2, 2 });*/


	// BOX
	/*lines.push_back({ { 1, 1 }, { 1, 2 } });
	lines.push_back({ { 1, 2 }, {2, 2 } });
	lines.push_back({ { 2, 2 }, {2, 1 } });
	lines.push_back({ { 2, 1 }, {1, 1 } });*/

	// five point STAR
	lines.push_back({ { 4, 4 }, { 0, 4 } });
	lines.push_back({ { 0, 4 }, { 3.5, 1 } });
	lines.push_back({ { 3.5, 1 }, { 2, 6 } });
	lines.push_back({ { 2, 6 }, { 0.5, 1 } });
	lines.push_back({ { 0.5, 1 }, { 4, 4 } });
}
