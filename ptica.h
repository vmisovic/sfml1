#pragma once
#include <SFML\Graphics.hpp>
class ptica
{
	float visina=280;
	float brzina = -10;
	float gravitacija = 1.5;
	int prethodni_frejm=0;
	float brzina_skoka = -15.0f;
	sf::RenderWindow* prozor;
public:
	ptica(sf::RenderWindow* prozor1);
	void osvezi(int trenutni_frejm);
	void crtaj(sf::Sprite& sprite);
	void skok();
};

