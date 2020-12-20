#include "Matrix.h"
#include <iostream>
#include "TwoDObject.h"

#pragma once
class ExpanseHelper
{
public:
    void printMatrix(const Matrix& m);
    //Translation
    Matrix getTranslationMatrix(double xChange, double yChange, double zChange);
    TwoDObject translateMatrix(TwoDObject& object, double xChange, double yChange);

    //Scale
    Matrix getScalingMatrix(double xScale, double yScale, double zScale);
    TwoDObject scaleOnLocation(TwoDObject& object, double xScale, double yScale);

    //Rotate
    Matrix getRotationMatrix(double degrees);
    TwoDObject rotate(TwoDObject& object, double degrees);
    TwoDObject rotateAroundOrigin(TwoDObject& object, double degrees);
private:

};