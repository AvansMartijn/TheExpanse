#include "Vector.h"

#ifndef math
#include <math.h>
#endif

//Constructors
Vector::Vector() : x(0), y(0), z(0) {}
Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

// operator with vector

//Optellen
Vector Vector::operator+ (const Vector& operand) {
    return Vector(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

//Aftrekken
Vector Vector::operator- (const Vector& operand) {
    return Vector(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

//Vermenigvuldigen
Vector Vector::operator* (const Vector& operand) {
    return Vector(this->x * operand.x, this->y * operand.y, this->z * operand.z);
}

//operator with scalar
//Optellen
Vector Vector::operator+ (int operand) {
    return Vector(this->x + operand, this->y + operand, this->z + operand);
}

//Aftrekken
Vector Vector::operator- (int operand) {
    return Vector(this->x - operand, this->y - operand, this->z - operand);
}

//Vermenigvuldigen
Vector Vector::operator* (int operand) {
    return Vector(this->x * operand, this->y * operand, this->z * operand);
}