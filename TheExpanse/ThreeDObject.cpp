#include "ThreeDObject.h"
#include "ExpanseHelper.h"

void ThreeDObject::calculateAABB()
{
	Vector min = centerPoint;
	Vector max = centerPoint;
	for (const Vector& point : points) {

		if (point.x < min.x) {
			min.x = point.x;
		}
		if (point.y < min.y) {
			min.y = point.y;
		}
		if (point.z < min.z) {
			min.z = point.z;
		}

		if (point.x > max.x) {
			max.x = point.x;
		}
		if (point.y > max.y) {
			max.y = point.y;
		}
		if (point.z > max.z) {
			max.z = point.z;
		}
	}

	AABB = { min, max };
}
