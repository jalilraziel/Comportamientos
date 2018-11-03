#pragma once
#include "cVector2.h"
class cGameObject
{
protected:
	cVector2 Position;
public:
	cVector2 GetPosition() { return Position; };
	void SetPosition(float, float);
	void SetPosition(cVector2);
	cGameObject();
	virtual ~cGameObject();
};

