#include <iostream>
#include <SFML\Graphics.hpp>
#include "stub.h"
#include "ptica.h"
int main()
{
    sf::RenderWindow prozor(sf::VideoMode(800, 600), "fljepi brd!",sf::Style::Close);
    prozor.setFramerateLimit(120);


    sf::Texture texture1,texture2;
    sf::Sprite sprite1,sprite2;
    if (!(texture1.loadFromFile("pozadina.png")))
        std::cout << "Cannot load image1"<<std::endl;
    if (!(texture2.loadFromFile("ptica.png")))
        std::cout << "Cannot load image2" << std::endl;
    texture2.getSize().x;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    ptica pticica(&sprite2,&prozor);//objekat klase ptica nazvan je pticica

    bool zivot=1;//da li je pricica jos uvek ziva
    stub s[5];//deklarisemo pet stubova (posto ce se vrteti u krug, nije nam potrebno vise) random imaju random visinu
    for (int i = 0; i < 5; i++)
    {
        s[i].povezi_grafiku(&prozor, prozor.getSize().x + i * 200);
        /*
        povezivanje grafike, i inicijalizacija x kordinate
        na pocetku se svi stubovi nalaze van prozora kako bi dali igracu nekoliko sekundi prednsti
        nalaze se na istom rastojanju od 200px
        */
    }

    while (prozor.isOpen())
    {
        sf::Event evnt;
        while (prozor.pollEvent(evnt))
        {
            prozor.clear(); 
            switch (evnt.type)
            {
            case sf::Event::Closed:
                prozor.close();
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%d", evnt.text.unicode);
                    if (evnt.text.unicode == ' ')
                        pticica.skok();
                }
                
            }
        }
        if (zivot)
        {
            prozor.draw(sprite1);//pozadina se crta na pocetku

            for (int i = 0; i < 5; i++)//pet stubova koji se vrte u krug i iscrtavanje
            {
                s[i].crtaj();
                if(s[i].provera(pticica.getPosition(), pticica.getSize(),pticica.ugao())==0)
                    zivot = 0;
                if (zivot == 0)
                {
                    sf::RectangleShape k;
                    k.setSize(sf::Vector2f(50, 50));
                    prozor.draw(k);
                }
                s[i].pomeri();
            }

            pticica.osvezi();//gravitacija (ptica ubrzava na dole)
            pticica.crtaj();//iscrtavanje ptice

            //iscrtavanje frejma i potom njegovo brisanje
            prozor.display();
            prozor.clear();
        }
    }
	return 0;
}
