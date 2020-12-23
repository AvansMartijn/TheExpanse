#include "Vector.h"

#ifndef math
#include <math.h>
#endif

//Constructors
Vector::Vector() : x(0), y(0), z(0), w(0) {}
Vector::Vector(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

// operator with vector

//Optellen
Vector Vector::operator+ (const Vector& operand) {
    return Vector(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

//Aftrekken
Vector Vector::operator- (const Vector& operand) {
    return Vector(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

//Vermenigvuldigen = Inproduct
double Vector::operator* (const Vector& operand) {
    return (x * operand.x) + (y * operand.y) + (z * operand.z);
}


//cross/outproduct 
Vector Vector::crossProduct(const Vector& operand) {
    Vector v;
    v.x = this->y * operand.z - this->z * operand.y;
    v.y = this->z * operand.x - this->x * operand.z;
    v.z = this->x * operand.y - this->y * operand.x;

    return v;
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