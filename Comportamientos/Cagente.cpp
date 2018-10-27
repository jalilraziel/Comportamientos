#include "Cagente.h"
#include "math.h"
#include "cVector2.h"
#include <stdlib.h>
#include <time.h> 


cBoid::cBoid()
{
	Dir.x = 0; 
	Dir.y = 0;
	Rad = 3;
}

cBoid::cBoid(int a, int b)
{
	Dir.x = a;
	Dir.y = b;
	Rad = 3;
}

cBoid::~cBoid()
{
}

cVector2 cBoid::GetDir()
{
	return Dir;
}

void cBoid::SetDir(cVector2 dir)
{
	Dir.x = dir.x;
	Dir.y = dir.y;
}

cVector2 cBoid::Seek(cVector2 pos, float mag)
{
	cVector2 nuevo = (pos - Position);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Flee(cVector2 pos, float mag)
{

	cVector2 nuevo = (Position - pos);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Parsue(cVector2 pos, float rad, float mag, float tiem)
{
	cVector2 nuevo = Seek(GetDir()*tiem, mag);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Evade(cVector2 pos, float rad, float mag, float tiem)
{
	cVector2 nuevo = Flee(GetDir()*tiem, mag);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Wander_Ramdom()
{
	srand(time(NULL));
	int a, b;
	a = rand() % 21 + (-10);
	b = rand() % 21 + (-10);
	cVector2 nuevo(a, b);
	return nuevo;
}

cVector2 cBoid::Wander_dir(float dis, float rad, float ang, float mag)
{
	srand(time(NULL));
	cVector2 center_circle = Position + (Dir*dis);
	cVector2 nuevo(cos(atan(Dir.y / Dir.x) + ((rand() % 11 + (-5) / 10))*ang*rad), sin(atan(Dir.y / Dir.x) + ((rand() % 11 + (-5) / 10))*ang*rad));
	cVector2 nuevo1 = (nuevo - Position);
	nuevo1.normalize();
	nuevo1*= mag;
	return nuevo1;
}

cVector2 cBoid::Follow_path(cVector2 prev, cVector2 next, float mag)
{

	cVector2 dis = (next - prev);
	cVector2 pos = (Position - prev);
	cVector2 a = Seek(next, 1);
	a.normalize;
	cVector2 b = a.projection(next);
	b.normalize;
	cVector2 nuevo = (a + b);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo;
}


cVector2 cBoid::Patrol()
{

	//nuevo.normalized();
	return cVector2();
}
