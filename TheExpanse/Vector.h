#pragma once
class Vector
{
private:

public:
	int x;
	int y;
	Vector();
	Vector(float x, float y);
	Vector operator+(const Vector& operand);
	Vector operator-(const Vector& operand);
	Vector operator*(const Vector& operand);
};

