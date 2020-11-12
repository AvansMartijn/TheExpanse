#pragma once
class Vector
{
private:
	int x;
	int y;

public:
	Vector();
	Vector(float x, float y);
	Vector operator+(const Vector& operand);
	Vector operator-(const Vector& operand);
	Vector operator*(const Vector& operand);
};

