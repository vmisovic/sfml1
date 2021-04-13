#include "ptica.h"

void ptica::osvezi(int trenutni_frejm)
{
	if (prethodni_frejm + 20 == trenutni_frejm)
	{
		visina += brzina;
		brzina += gravitacija;
		prethodni_frejm = trenutni_frejm;
		if (visina > 500)
		{
			visina = 500;
			brzina = 0;
		}
		else if (visina < 10)
		{
			visina = 10;
		}
		if (brzina < -100)brzina = -100;
	}
}

void ptica::crtaj(sf::Sprite& sprite,sf::RenderWindow& prozor)
{
	sprite.setPosition(100.0f, visina);
	prozor.draw(sprite);
}

void ptica::skok()
{
	brzina = brzina_skoka;
}
