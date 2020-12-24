#include "Matrix.h"
#include <iostream>
#include "TwoDObject.h"
#include "ThreeDObject.h"

#pragma once
class ExpanseHelper
{
public:
    void printMatrix(const Matrix& m);
    //Translation
    Matrix getTranslationMatrix(double xChange, double yChange, double zChange);
    ThreeDObject translateMatrix(ThreeDObject& object, double xChange, double yChange, double zChange);

    //Scale
    Matrix getScalingMatrix(double xScale, double yScale, double zScale);
    ThreeDObject scaleOnLocation(ThreeDObject& object, double xScale, double yScale, double zScale);

    //Rotate
    Matrix getRotationMatrixZAxis(double degrees);
    Matrix getRotationMatrixYAxis(double degrees);
    Matrix getRotationMatrixXAxis(double degrees);
    ThreeDObject rotate(ThreeDObject& object, double degrees, char axis);
    ThreeDObject rotateAroundOrigin(ThreeDObject& object, double degrees, char axis);

    //CrossProduct
    Vector getCrossProduct(const Vector& vA, const Vector& vB);
    Vector normalize(const Vector& v);

    //transformation
    Matrix getInverseTransformationMatrix(const Vector& right, const Vector& up, const Vector& direction);

    //projection
    Matrix getProjectionMatrix(double near, double far, double fovY);

    Vector correctProjection(const Vector& vector, double screenSizeX, double screenSizeY);

private:

    const double PI = atan(1) * 4;

};