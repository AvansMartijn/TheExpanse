#include "Camera.h"
Camera::Camera() {
	eye = { 0,0,0,1 };
	lookAt = { 0,0,-5,1 };
	up = { 0, 1, 0, 1 };
	//find direction
	direction = eye - lookAt;
	//normalize direction
	direction = helper.normalize(direction);
	//find right
	right = helper.getCrossProduct(up, direction);
	//normalize right
	right = helper.normalize(right);
	//find up
	up = helper.getCrossProduct(direction, right);
	//normalize up
	up = helper.normalize(up);

	//fov on y-axis 90 degrees
	fovY = 90;
	near = 0.1;
	far = 100;


}

ThreeDObject Camera::createPerspective(const ThreeDObject& object)
{
	ThreeDObject viewObject;

	//put them in a transformationmatrix
	Matrix inverseTransformationMatrix = helper.getInverseTransformationMatrix(right, up, direction);

	//translate to origin
	Matrix toOrigin = helper.getTranslationMatrix(-eye.x, -eye.y, -eye.z);

	Matrix cameraPerspectiveMatrix = inverseTransformationMatrix * toOrigin;

	//Camera
	viewObject.centerPoint = cameraPerspectiveMatrix * object.centerPoint;
	for (size_t i = 0; i < object.points.size(); i++)
	{
		viewObject.points[i] = cameraPerspectiveMatrix * object.points[i];
	}

	//Perspectief
	Matrix pers = helper.getProjectionMatrix(near, far, fovY);

	viewObject.centerPoint = pers * viewObject.centerPoint;
	viewObject.centerPoint = helper.correctProjection(viewObject.centerPoint, 1080, 720);
	for (size_t i = 0; i < viewObject.points.size(); i++)
	{
		Vector newView = pers * viewObject.points[i];
		viewObject.points[i] = helper.correctProjection(newView, 1080, 720);
	}

	return viewObject;
}
