#include "Matrix.h"
#include <iostream>
#include "TwoDObject.h"

#pragma once
class ExpanseHelper
{
public:
    void printMatrix(const Matrix& m);
    Matrix getTranslationMatrix(int xChange, int yChange);
    Matrix getScalingMatrix(int xScale, int yScale);
    TwoDObject scaleOnLocation(TwoDObject& object, int xScale, int yScale);

private:

};