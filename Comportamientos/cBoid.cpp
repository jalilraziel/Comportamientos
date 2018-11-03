#include "cBoid.h"
#include "math.h"
#include "cVector2.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <sfml\Graphics.hpp>

cBoid::cBoid()
{
	Dir.x = 0; 
	Dir.y = 1;
}

cBoid::cBoid(float a, float b)
{
	Dir.x = a;
	Dir.y = b;
	Dir.normalize();
}

cBoid::~cBoid()
{
}

#define MAX_FORCE 10
#define SEEK_FORCE 5
#define MAX_SPEED 10

void cBoid::Update(float deltaTime)
{
	cVector2 steeringForce;
	if (m_bDoSeek) {
		steeringForce += Seek(m_SeekTarget, SEEK_FORCE);
	}
	if (m_bDoFlee) {
		steeringForce += Flee(m_FleeTarget, SEEK_FORCE, 70);
	}
	if (m_bDoParsue) {
		steeringForce += Parsue(m_ParsueTarget, SEEK_FORCE, 70, 2);
		
	}

	cVector2 newDir = steeringForce + Dir;
	cVector2 newPos = Position + (newDir * MAX_SPEED * deltaTime).truncate(MAX_FORCE);

	Position = newPos;
	Dir = newDir.normalized();

	//cVector2 mov = Jugador.Seek(cVector2(bandera.getPosition().x, bandera.getPosition().y), 1);

	/*
	mov += Jugador.Flee(cVector2(rock.getPosition().x, rock.getPosition().y), 1, rock.getRadius() + player.getRadius() + 5);
	mov += Jugador.GetDir();
	mov.normalize();
	mov += Jugador.GetDir();
	mov.normalize();
	Jugador.SetDir(mov);
	*/
}

void cBoid::Draw(sf::RenderTarget* pRT)
{
	//Dibuja un shape circular en la posicion de mi 
	sf::CircleShape objShape;
	objShape.setRadius(20);
	objShape.setOrigin(20, 20);
	objShape.setPosition(Position.x, Position.y);
	objShape.setFillColor(m_Color);

	cVector2 dirDefaz = Position + Dir * 50;

	sf::Vertex objDir[2];
	objDir[0].position = sf::Vector2f(Position.x, Position.y);
	objDir[1].position = sf::Vector2f(dirDefaz.x, dirDefaz.y);

	pRT->draw(objShape);
	pRT->draw(objDir, 2, sf::Lines);
}

cVector2 cBoid::GetDir()
{
	return Dir;
}

void cBoid::SetDir(cVector2 dir)
{
	Dir.x = dir.x;
	Dir.y = dir.y;
	Dir.normalize();
}

void cBoid::SetDir(float a, float b)
{
	SetDir({ a, b });
}

cVector2 cBoid::Seek(cVector2 pos, float mag)
{
	cVector2 nuevo = (pos - Position);
	nuevo.normalize();
	return nuevo * mag;
}

cVector2 cBoid::Flee(cVector2 pos, float mag, float rad)
{
	cVector2 nuevo = (Position - pos);
	if (nuevo.Mag() < rad)
	{
		nuevo.normalize();
		nuevo *= mag;
		return nuevo;
	}
	else
	{
		return cVector2(0, 0);
		std::cout << "llegamos a 0,0" << std::endl;
	}
}

cVector2 cBoid::Parsue(cVector2 pos, float mag, float rad, float tiem)
{
	cVector2 nuevo = pos;
	if (nuevo.Mag() > rad){
		nuevo = this->Seek(pos*tiem, mag);
		return nuevo;
		}
	else {
		return cVector2(0, 0);
		std::cout << "llegamos a 0,0" << std::endl;
	}
}

cVector2 cBoid::Evade(cVector2 pos, float mag, float rad, float tiem)
{
	cVector2 nuevo = pos;
	if (nuevo.Mag() < rad){
		nuevo = Flee(GetPosition()*tiem, mag, rad) + Flee(GetPosition(), mag, rad);
		return nuevo;
	}
	else{
		return cVector2(0, 0);
		std::cout << "llegamos a 0,0" << std::endl;
	}
}

cVector2 cBoid::Wander_Ramdom()
{
	srand(time(NULL));
	float a, b;
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
	a.normalize();
	cVector2 b = a.projection(next);
	b.normalize();
	cVector2 nuevo = (a + b);
	nuevo.normalize();
	nuevo *= mag;
	return nuevo                                                                                                                                                                                                                     ;
}


cVector2 cBoid::Patrol()
{

	//nuevo.normalized();
	return cVector2();
}
