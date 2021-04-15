#include "ptica.h"

ptica::ptica(sf::Sprite* sprite1, sf::RenderWindow* prozor1)
{
	sprite = sprite1;
	prozor = prozor1;
}

void ptica::osvezi()
{
	visina += brzina;
	brzina += gravitacija;
	if (visina >= prozor->getSize().y-110)
	{
		visina = prozor->getSize().y - 110;
		brzina = 0;
	}
	else if (visina < 10)
	{
		visina = 10;
		brzina = 0;
	}
	if (brzina < -100)
		brzina = -100;
	
}

void ptica::crtaj()
{
	sprite->setPosition(100.0f, visina);
	if(visina > 20)
	sprite->rotate(brzina * 5.0f);
	prozor->draw(*sprite);
	if (visina > 20)
	sprite->rotate(-brzina*5.0f);
}

void ptica::skok()
{
	brzina = brzina_skoka;
}
