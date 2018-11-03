#pragma once
#include "cObjetoDeJuego.h"

#include <vector>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

class cBoid : public cGameObject
{
protected:
	cVector2 Dir;
	sf::Color m_Color;
	bool m_bDoParsue = false;
	bool m_bDoSeek = false;
	bool m_bDoFlee = false;
	cVector2 m_SeekTarget;
	cVector2 m_FleeTarget;
	cVector2 m_ParsueTarget;
public:
	
	cVector2 GetDir();
	void SetDir(cVector2 dir);
	void SetDir(float a, float b);
	
	cVector2 Seek(cVector2 pos, float mag);
	cVector2 Flee(cVector2 pos, float mag, float rad);
	cVector2 Parsue(cVector2, float mag, float rad, float tiem);
	cVector2 Evade(cVector2, float mag, float rad, float tiem);
	cVector2 Wander_Ramdom();
	cVector2 Wander_dir(float dis, float rad, float ang, float mag);
	cVector2 Follow_path(cVector2 prev, cVector2 next, float rad);
	cVector2 Patrol();
	
	cBoid();
	cBoid(float a, float b);
	~cBoid();

	void SetSeekState(bool bVal) { m_bDoSeek = bVal; }
	void SetSeekTarget(const cVector2& seekPos) {
		m_SeekTarget = seekPos;
	}
	void SetFleeState(bool bVal) { m_bDoFlee = bVal; }
	void SetFleeTarget(const cVector2& fleePos) {
		m_FleeTarget = fleePos;
	}
	void SetParsueState(bool bVal) { m_bDoParsue = bVal; }
	void SetParsueTarget(const cVector2& parsuePos) {
		m_ParsueTarget = parsuePos;
	}

	void Update(float deltaTime);
	void Draw(sf::RenderTarget* pRT);
	void SetColor(const sf::Color& color) { m_Color = color; }
	sf::Color GetColor() { return m_Color; }
};

