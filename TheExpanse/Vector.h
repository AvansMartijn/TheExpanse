#pragma once
class Vector
{
private:

public:
	double x;
	double y;
	double z;
	Vector();
	Vector(double x, double y, double z = 1); //Z=1 for 2d Compatibility
	Vector operator+(const Vector& operand);
	Vector operator-(const Vector& operand);
	Vector operator*(const Vector& operand);
	Vector operator+(int operand);
	Vector operator-(int operand);
	Vector operator*(int operand);
};

