#include "Cagente.h"
#include "cVector2.h"


cBoid::cBoid()
{
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
	
	return cVector2();
}

cVector2 cBoid::Flee(cVector2 pos, float mag)
{

	return cVector2();
}

cVector2 cBoid::Parsue(cVector2, float mag, float tiem)
{
	return cVector2();
}

cVector2 cBoid::Evade(cVector2, float mag, float tiem)
{
	return cVector2();
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
