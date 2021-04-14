#include "ptica.h"
ptica::ptica(sf::RenderWindow* prozor1)
{
	prozor = prozor1;
}

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

void ptica::crtaj(sf::Sprite& sprite)
{
	sprite.setPosition(100.0f, visina);
	sprite.rotate(-(prozor->getSize().y / 2 - visina)*0.1);
	prozor->draw(sprite);
	sprite.rotate((prozor->getSize().y / 2 - visina)*0.1);
}

void ptica::skok()
{
	brzina = brzina_skoka;
}
