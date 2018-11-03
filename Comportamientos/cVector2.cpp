#include "cVector2.h"
#include  <math.h>

cVector2::cVector2()
{
	x = 0.0f;
	y = 0.0f;
}

cVector2::cVector2(float a, float b)
{
	x = a;
	y = b;
}

cVector2 cVector2::normalized()
{
	float a = x / Mag(), b = y / Mag();
	cVector2 nuevo;
	nuevo.x = a;
	nuevo.y = b;
	return nuevo;
}

void cVector2::normalize()
{
	float a = x / Mag(), b = y / Mag();
	x = a;
	y = b;
}

float cVector2::Mag()
{
	float E = ((x*x)+(y*y));
	float A = sqrt(E);
	return A;
}

float cVector2::ang()
{
	float A = atan2(x, y);
	return A;
}

float cVector2::dot(cVector2 other)
{
	float A = ((x * other.x) + (y * other.y));
	return A;
}

cVector2& cVector2::truncate(float maxMag)
{
	float mag = Mag();
	if (mag > maxMag) {
		normalize();
		*this *= maxMag;
	}

	return *this;
}

cVector2 cVector2::projection(cVector2 other)
{
	cVector2 projection = other;
	projection *= (dot(other)/pow(Mag(), 2));
	return projection;
}

cVector2 cVector2::cross(cVector2 other)
{
	return cVector2();
}

cVector2 cVector2::operator+(cVector2 other)
{
	cVector2 nuevo;
	nuevo.x = x + other.x;
	nuevo.y = y + other.y;
	return nuevo;
}

void cVector2::operator+=(cVector2 other)
{
	x += other.x;
	y += other.y;
}

cVector2 cVector2::operator-(cVector2 other)
{
	cVector2 nuevo;
	nuevo.x = x - other.x;
	nuevo.y = y - other.y;
	return nuevo;
}

void cVector2::operator-=(cVector2 other)
{
	x -= other.x;
	y -= other.y;
}

cVector2 cVector2::operator*(float veces)
{
	cVector2 nuevo;
	nuevo.x = x * veces;
	nuevo.y = y * veces;
	return nuevo;
}

void cVector2::operator*=(float veces)
{
	x *=  veces;
	y *= veces;
}

cVector2 cVector2::operator/(float veces)
{
	cVector2 nuevo;
	nuevo.x = x / veces;
	nuevo.y = y / veces;
	return nuevo;
}

void cVector2::operator/=(float veces)
{
	x /= veces;
	y /= veces;
}

void cVector2::operator=(cVector2 other)
{
	x = other.x;
	y = other.y;
}

bool cVector2::operator==(cVector2 other)
{
	if (x == other.x && y == other.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cVector2::operator!=(cVector2 other)
{
	if (x == other.x && y == other.y)
	{
		return false;
	}
	else
	{
		return true;
	}
}
