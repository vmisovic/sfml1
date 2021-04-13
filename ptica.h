#pragma once
#include <SFML\Graphics.hpp>
class ptica
{
	float visina=280;
	float brzina = -10;
	float gravitacija = 1.5;
	int prethodni_frejm=0;
	float brzina_skoka = -17;
public:
	void osvezi(int trenutni_frejm);
	void crtaj(sf::Sprite& sprite,sf::RenderWindow& prozor);
	void skok();
};

