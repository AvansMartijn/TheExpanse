#include "Matrix.h"
#include <iostream>
#include "TwoDObject.h"

#pragma once
class ExpanseHelper
{
public:
    void printMatrix(const Matrix& m);
    Matrix getTranslationMatrix(double xChange, double yChange);
    Matrix getScalingMatrix(double xScale, double yScale);
    TwoDObject scaleOnLocation(TwoDObject& object, double xScale, double yScale);

private:

};