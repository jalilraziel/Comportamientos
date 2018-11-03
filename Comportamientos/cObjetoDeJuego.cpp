#include "cObjetoDeJuego.h"

void cGameObject::SetPosition(float X, float Y)
{
	Position.x = X;
	Position.y = Y;
}

void cGameObject::SetPosition(cVector2 a)
{
	Position.x = a.x;
	Position.y = a.y;
}

cGameObject::cGameObject()
{
	Position.x = 0;
	Position.y = 0;
}


cGameObject::~cGameObject()
{
}
