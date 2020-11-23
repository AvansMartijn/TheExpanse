#include "Vector.h"

#ifndef math
#include <math.h>
#endif

//Constructors
Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}


// operator with vector

//Optellen
Vector Vector::operator+ (const Vector& operand) {
    return Vector(this->x + operand.x, this->y + operand.y);
}

//Aftrekken
Vector Vector::operator- (const Vector& operand) {
    return Vector(this->x - operand.x, this->y - operand.y);
}

//Vermenigvuldigen
Vector Vector::operator* (const Vector& operand) {
    return Vector(this->x * operand.x, this->y * operand.y);
}

//operator with scalar
//Optellen
Vector Vector::operator+ (int operand) {
    return Vector(this->x + operand, this->y + operand);
}

//Aftrekken
Vector Vector::operator- (int operand) {
    return Vector(this->x - operand, this->y - operand);
}

//Vermenigvuldigen
Vector Vector::operator* (int operand) {
    return Vector(this->x * operand, this->y * operand);
}