
#include <sfml\Graphics.hpp>
#include "cBoid.h"
#include <vector>

using std::vector;

sf::RenderWindow* g_pWindow;
std::vector<cBoid> g_listaBoids;

void UpdateInputs(const sf::Event& evento)
{
	cVector2 nDir(g_listaBoids[0].GetDir());

	if (evento.type == sf::Event::KeyPressed)
	{
		if (evento.key.code == sf::Keyboard::W) {
			nDir.x = 0; nDir.y = -1;
		}
		if (evento.key.code == sf::Keyboard::A) {
			nDir.x = -1; nDir.y = 0;
		}
		if (evento.key.code == sf::Keyboard::S) {
			nDir.x = 0; nDir.y = 1;
		}
		if (evento.key.code == sf::Keyboard::D) {
			nDir.x = 1; nDir.y = 0;
		}

		/*
		if (evento.key.code == sf::Keyboard::Q) {
			SeekAndFlee = true;
			ParsueAndEvade = true;
		}
		*/
		
		g_listaBoids[0].SetDir(nDir.x, nDir.y);
	}
}

void Update()
{
	for (auto& boid : g_listaBoids) {
		boid.Update(1.0f/60.0f);
	}

	/*
	if (SeekAndFlee == true)
	{
		cVector2 mov = Jugador.Seek(cVector2(bandera.getPosition().x, bandera.getPosition().y), 1);
		mov += Jugador.Flee(cVector2(rock.getPosition().x, rock.getPosition().y), 1, rock.getRadius() + player.getRadius() + 5);
		mov += Jugador.GetDir();
		mov.normalize();
		mov += Jugador.GetDir();
		mov.normalize();
		Jugador.SetDir(mov);
		player.setPosition(sf::Vector2f(mov.x + player.getPosition().x, mov.y + player.getPosition().y));
		Jugador.SetPosition(mov.x + player.getPosition().x, mov.y + player.getPosition().y);
	}
	*/
	/*
	if (ParsueAndEvade == true)
	{
		cVector2 mov_amibo = Jugador_amibo.Parsue(Jugador.GetPosition(), 2, 120, 2);
		//cVector2 mov_amibo = Jugador_amibo.Seek(cVector2(Jugador.GetPosition().x, Jugador.GetPosition().y), 2);
		if (mov_amibo == cVector2(0, 0))
		{
			mov_amibo = Jugador_amibo.Seek(cVector2(Jugador.GetPosition().x, Jugador.GetPosition().y), 1);
			mov_amibo += Jugador_amibo.GetDir();
			mov_amibo.normalize();
			Jugador_amibo.SetDir(mov_amibo);
		}
		else
		{
			mov_amibo += Jugador_amibo.Flee(cVector2(rock.getPosition().x, rock.getPosition().y), 1, rock.getRadius() + player.getRadius() + 5);
			mov_amibo += Jugador_amibo.GetDir();
			mov_amibo.normalize();
			Jugador_amibo.SetDir(mov_amibo);
			player_amibo.setPosition(sf::Vector2f(mov_amibo.x + player_amibo.getPosition().x, mov_amibo.y + player_amibo.getPosition().y));
			Jugador_amibo.SetPosition(mov_amibo.x + player_amibo.getPosition().x, mov_amibo.y + player_amibo.getPosition().y);
		}

		cVector2 mov_No_amibo = Jugador_No_amibo.Evade(Jugador.GetPosition(), 2, 80, 2);
		if (mov_No_amibo == cVector2(0, 0))
		{

		}
		else
		{
			mov_No_amibo += Jugador_No_amibo.Flee(cVector2(rock.getPosition().x, rock.getPosition().y), 1, rock.getRadius() + player.getRadius() + 5);
			mov_No_amibo += Jugador_No_amibo.GetDir();
			mov_No_amibo.normalize();
			Jugador_No_amibo.SetDir(mov_No_amibo);

			//player_No_amibo.setPosition(sf::Vector2f(mov_No_amibo.x + player_No_amibo.getPosition().x, mov_No_amibo.y + player_No_amibo.getPosition().y));
			//Jugador_No_amibo.SetPosition(mov_No_amibo.x + player_No_amibo.getPosition().x, mov_No_amibo.y + player_No_amibo.getPosition().y);
		}

	}
	*/
}

void Render()
{
	g_pWindow->clear();

	sf::CircleShape bandera;
	bandera.setRadius(12);
	bandera.setOrigin(6, 6);
	bandera.setPosition(540, 360);
	bandera.setFillColor(sf::Color::Blue);

	sf::CircleShape rock;
	rock.setRadius(40);
	rock.setOrigin(40, 40);
	rock.setPosition(180, 120);
	rock.setFillColor(sf::Color(130, 130, 130));

	g_pWindow->draw(bandera);
	g_pWindow->draw(rock);

	for (auto& boid : g_listaBoids) {
		boid.Draw(g_pWindow);
	}

	g_pWindow->display();
}

int main()
{
	unsigned int ancho = 720, alto = 480;
	float velocity = 3;
	float pos = 25;

	g_pWindow = new sf::RenderWindow(sf::VideoMode(ancho, alto), "steering behaviors");
	g_pWindow->setFramerateLimit(60);

	g_listaBoids.emplace_back();
	cBoid& miBoid = g_listaBoids.back();
	miBoid.SetPosition(25, 25);
	miBoid.SetColor(sf::Color::Green);
	miBoid.SetSeekState(true);
	miBoid.SetSeekTarget({ 540, 360 });
	miBoid.SetFleeState(true);
	miBoid.SetFleeTarget({ 180, 120 });

	g_listaBoids.emplace_back();
	cBoid& miBoid1 = g_listaBoids.back();
	miBoid1.SetPosition(50, 50);
	miBoid1.SetColor(sf::Color(0, 150, 0));
	miBoid1.SetParsueState(true);
	miBoid1.SetParsueTarget({miBoid.GetPosition()});

	g_listaBoids.emplace_back();
	cBoid& miBoid2 = g_listaBoids.back();
	miBoid2.SetPosition(250, 220);
	miBoid2.SetColor(sf::Color::Yellow);

	bool SeekAndFlee = false;
	bool ParsueAndEvade = false;
	sf::Event evento;

	while (g_pWindow->isOpen()){
		while (g_pWindow->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				g_pWindow->close();
			}
		}

		Update();
		Render();
	}

	delete g_pWindow;

	return 0;
}