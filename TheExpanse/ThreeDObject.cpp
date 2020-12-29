#include "ThreeDObject.h"
#include "ExpanseHelper.h"

void ThreeDObject::pulseObject()
{
	ExpanseHelper helper;
	if (pulseData.growTimes > 0) {
		if (pulseData.isGrowing) {
			//Matrix scalingsMatrix = helper.getScalingMatrix(pulseData.growMultiplier, pulseData.growMultiplier, pulseData.growMultiplier);
			Matrix translationMatrixToOrigin = helper.getTranslationMatrix(-this->centerPoint.x, -this->centerPoint.y, -this->centerPoint.z);
			Matrix translationMatrixBack = helper.getTranslationMatrix(this->centerPoint.x, this->centerPoint.y, this->centerPoint.z);
			Matrix scalingMatrix = helper.getScalingMatrix(pulseData.growMultiplier, pulseData.growMultiplier, pulseData.growMultiplier);

			Matrix superMatrix = translationMatrixBack * scalingMatrix * translationMatrixToOrigin;

			//Scaling around centerpoint does not change centerpoint
			for (int i = 0; i < this->points.size(); i++)
			{
				this->points[i] = superMatrix * this->points[i];
			}
			pulseData.growCounter++;
			if (pulseData.growCounter >= pulseData.growTimes) {
				pulseData.isGrowing = false;
			}
		}
		else {
			//Matrix scalingsMatrix = helper.getScalingMatrix(pulseData.shrinkMultiplier, pulseData.shrinkMultiplier, pulseData.shrinkMultiplier);
			Matrix translationMatrixToOrigin = helper.getTranslationMatrix(-this->centerPoint.x, -this->centerPoint.y, -this->centerPoint.z);
			Matrix translationMatrixBack = helper.getTranslationMatrix(this->centerPoint.x, this->centerPoint.y, this->centerPoint.z);
			Matrix scalingMatrix = helper.getScalingMatrix(1 / pulseData.growMultiplier, 1 / pulseData.growMultiplier, 1 / pulseData.growMultiplier);

			Matrix superMatrix = translationMatrixBack * scalingMatrix * translationMatrixToOrigin;

			//Scaling around centerpoint does not change centerpoint
			for (int i = 0; i < this->points.size(); i++)
			{
				this->points[i] = superMatrix * this->points[i];
			}
			pulseData.growCounter--;
			if (pulseData.growCounter <= 0) {
				pulseData.isGrowing = true;
			}
		}
	}
}
