#include "Matrix.h"
#include <iostream>
#include "TwoDObject.h"
#include "ThreeDObject.h"
#include "AABB.h"

#pragma once
class ExpanseHelper
{
public:
    //Translation
    Matrix getTranslationMatrix(double xChange, double yChange, double zChange);
    ThreeDObject translate(const ThreeDObject& object, double xChange, double yChange, double zChange);

    //Scale
    Matrix getScalingMatrix(double xScale, double yScale, double zScale);
    ThreeDObject scaleOnLocation(const ThreeDObject& object, double xScale, double yScale, double zScale);

    //Rotate
    Matrix getRotationMatrixZAxis(double degrees);
    Matrix getRotationMatrixYAxis(double degrees);
    Matrix getRotationMatrixXAxis(double degrees);
    ThreeDObject rotate(const ThreeDObject& object, double degrees, char axis);
    ThreeDObject rotateAroundOrigin(const ThreeDObject& object, double degrees, char axis);
    ThreeDObject roll(const ThreeDObject&, double degrees);
    ThreeDObject pitch(const ThreeDObject&, double degrees);
    ThreeDObject jaw(const ThreeDObject&, double degrees);
    Matrix getRollRotationMatrix(const ThreeDObject&, double degrees, const Vector& v);

    //CrossProduct
    Vector getCrossProduct(const Vector& vA, const Vector& vB);
    Vector normalize(const Vector& v);

    //transformation
    Matrix getInverseTransformationMatrix(const Vector& right, const Vector& up, const Vector& direction);

    //projection
    Matrix getProjectionMatrix(double near, double far, double fovY);
    Vector correctProjection(const Vector& vector, double screenSizeX, double screenSizeY);

    //collision
    AABB findAABB(const ThreeDObject& object);
    bool intersects(AABB a, AABB b);

    //misc
    ThreeDObject pulseObject(const ThreeDObject& object);
    Vector getForwardVector(const ThreeDObject& object);


private:
    const double PI = atan(1) * 4;

};