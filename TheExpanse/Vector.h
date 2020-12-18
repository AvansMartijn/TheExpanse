#pragma once
class Vector
{
private:

public:
	double x;
	double y;
	Vector();
	Vector(double x, double y);
	Vector operator+(const Vector& operand);
	Vector operator-(const Vector& operand);
	Vector operator*(const Vector& operand);
	Vector operator+(int operand);
	Vector operator-(int operand);
	Vector operator*(int operand);
};

