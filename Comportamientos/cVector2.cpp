#include "cVector2.h"
#include  <math.h>

cVector2::cVector2()
{
	x = 0;
	y = 0;
}

cVector2::cVector2(float a, float b)
{
	x = a;
	y = b;
}

cVector2 cVector2::normalized()
{
	cVector2 nuevo;
	nuevo.x = x / Mag();
	nuevo.y = y / Mag();
	return nuevo;
}

void cVector2::normalize()
{
	x = x / Mag();
	y = y / Mag();

}

float cVector2::Mag()
{
	float A = sqrt(pow(x, 2) + pow(x, 2));
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
	x *= x * veces;
	y *= y * veces;
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
	x /= x / veces;
	y /= y / veces;
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
