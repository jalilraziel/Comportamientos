#pragma once
struct  cVector2
{
	float x, y;
	cVector2();
	cVector2(float a, float b);
	cVector2 normalized();
	void normalize();
	float Mag();
	float ang();
	float dot(cVector2 b);
	cVector2& truncate(float maxMag);
	cVector2 projection(cVector2 other);
	cVector2 cross(cVector2 b);
	cVector2 operator+(cVector2 other);
	void operator+=(cVector2 other);
	cVector2 operator-(cVector2 other);
	void operator-=(cVector2 other);
	cVector2 operator*(float times);
	void operator*=(float times);
	cVector2 operator/(float times);
	void operator/=(float times);
	void operator=(cVector2 other);
	bool operator==(cVector2 other);
	bool operator!=(cVector2 other);
};