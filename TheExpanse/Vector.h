#pragma once
class Vector
{
private:

public:
	double x;
	double y;
	double z;
	double w;
	Vector();
	Vector(double x, double y, double z, double w = 1); //W=1 makes Vector a point instead of direction
	Vector operator+(const Vector& operand);
	Vector operator-(const Vector& operand);
	//Inproduct
	double operator*(const Vector& operand);
	Vector operator+(int operand);
	Vector operator-(int operand);
	Vector operator*(double operand);
};

