#include "Cagente.h"
#include "cVector2.h"


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

cBoid::cBoid(int a, int b, int c)
{
	Dir.x = a;
	Dir.y = b;
	Rad = c;
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
	nuevo.normalized();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Flee(cVector2 pos, float mag)
{

	cVector2 nuevo = (Position - pos);
	nuevo.normalized();
	nuevo *= mag;
	return nuevo;
}

cVector2 cBoid::Parsue(cVector2 pos, float mag, float tiem)
{
	cVector2 nuevo = Seek(GetDir()*tiem, mag);
	nuevo.normalized();
	return nuevo;
}

cVector2 cBoid::Evade(cVector2 pos, float mag, float tiem)
{
	cVector2 nuevo = Flee(GetDir()*tiem, mag);
	nuevo.normalized();
	return nuevo;
}

cVector2 cBoid::Wonder_Ramdom()
{
	return cVector2();
}

cVector2 cBoid::Wonder_dir()
{
	return cVector2();
}

cVector2 cBoid::Follow_path()
{
	return cVector2();
}

cVector2 cBoid::Patrol()
{
	return cVector2();
}
