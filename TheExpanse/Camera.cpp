#include "Camera.h"
#include "ExpanseHelper.h"
Camera::Camera() {
	ExpanseHelper helper;
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

	//put them in a transformationmatrix
	Matrix inverseTransformationMatrix = helper.getInverseTransformationMatrix(right, up, direction);

	//translate to origin
	Matrix toOrigin = helper.getTranslationMatrix(-eye.x, -eye.y, -eye.z);

	Matrix cameraPerspectiveMatrix = inverseTransformationMatrix* toOrigin;



	//fov on y-axis 90 degrees
	fovY = 90;
	near = 5;
	far = 10;


}