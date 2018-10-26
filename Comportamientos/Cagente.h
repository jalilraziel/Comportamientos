#pragma once
#include "cObjetoDeJuego.h"
class cBoid:cGameObject
{
private:
	cVector2 Dir;
	int Rad;
public:
	cVector2 GetDir();
	void SetDir(cVector2 dir);
	cVector2 Seek(cVector2 pos, float mag);
	cVector2 Flee(cVector2 pos, float mag);
	cVector2 Parsue(cVector2,float mag, float tiem);
	cVector2 Evade(cVector2, float mag, float tiem);
	cVector2 Wonder_Ramdom();
	cVector2 Wonder_dir();
	cVector2 Follow_path();
	cVector2 Patrol();
	cBoid();
	cBoid(int a,int b);
	cBoid(int a, int b,int c);
	~cBoid();
};

