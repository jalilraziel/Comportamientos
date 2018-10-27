#pragma once
#include "cObjetoDeJuego.h"
#include <vector> 
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
	cVector2 Parsue(cVector2, float rad, float mag, float tiem);
	cVector2 Evade(cVector2, float rad, float mag, float tiem);
	cVector2 Wander_Ramdom();
	cVector2 Wander_dir(float dis, float rad, float ang, float mag);
	cVector2 Follow_path(cVector2 prev, cVector2 next, float rad);
	cVector2 Patrol();
	cBoid();
	cBoid(int a,int b);
	~cBoid();
};

