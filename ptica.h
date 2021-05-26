#pragma once
#include <SFML\Graphics.hpp>
class ptica
{
	float visina=280;
	float x = 100.f;
	float brzina = -2.0f;
	float gravitacija = 0.1f;
	float brzina_skoka = -3.5f;
	sf::Sprite* sprite;
	sf::RenderWindow* prozor;
public:
	ptica(sf::Sprite* sprite1,sf::RenderWindow* prozor1);
	void osvezi();
	void crtaj();
	void skok();
	sf::Vector2u getSize();
	sf::Vector2u getPosition();
};

