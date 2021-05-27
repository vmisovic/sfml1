#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "stub.h"
#include "ptica.h"
bool rezultati(sf::RenderWindow *prozor, sf::Font font,int skor)
{
    sf::RectangleShape k;
    k.setSize(sf::Vector2f(prozor->getSize().x * 0.6f, prozor->getSize().y * 0.6f));
    k.setPosition(sf::Vector2f(sf::Vector2f(prozor->getSize().x * 0.2f, prozor->getSize().y * 0.2f)));
    k.setFillColor(sf::Color(1, 1, 1, 200));
    prozor->draw(k);

    sf::Text kraj, osvojeno, tip, komentar;
    kraj.setFont(font);
    kraj.setCharacterSize(35);
    kraj.setPosition(0.4f * prozor->getSize().x, 0.25f * prozor->getSize().y);
    kraj.setString("KRAJ IGRE");
    prozor->draw(kraj); 

    osvojeno.setFont(font);
    osvojeno.setCharacterSize(20);
    osvojeno.setPosition(0.3f * prozor->getSize().x, 0.35f * prozor->getSize().y);
    std::stringstream ss;
    ss << "Osvojili ste ukupno " << skor << " poena.";
    osvojeno.setString(ss.str().c_str());
    prozor->draw(osvojeno);

    tip.setFont(font);
    tip.setCharacterSize(15);

    komentar.setFont(font);
    komentar.setCharacterSize(20);
}

void poeni(sf::RenderWindow *prozor,sf::Font font, int skor)
{
    sf::Text ispis;
    ispis.setFont(font);
    ispis.setCharacterSize(30);
    //ispis.setColor(sf::Color::Yellow);
    ispis.setOutlineColor(sf::Color::Black);
    ispis.setOutlineThickness(2);
    std::stringstream ss;
    ss << skor;
    ispis.setPosition(0.85f * prozor->getSize().x, 0.05f * prozor->getSize().y);
    ispis.setString(ss.str().c_str());
    prozor->draw(ispis);
}


int main()
{
    sf::RenderWindow prozor(sf::VideoMode(800, 600), "fljepi brd!",sf::Style::Close);
    prozor.setFramerateLimit(120);

    sf::Texture texture1,texture2;
    sf::Sprite sprite1,sprite2;
    if (!(texture1.loadFromFile("resource/pozadina.png")))
        std::cout << "Cannot load image1"<<std::endl;
    if (!(texture2.loadFromFile("resource/ptica.png")))
        std::cout << "Cannot load image2" << std::endl;
    sf::Font font;
    if (!font.loadFromFile("resource/sansation.ttf"))
        return EXIT_FAILURE;
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

    int brojac = 0;//ukupan skor je broj stubova koje je igrac preskocio
    printf("Brojac: %d\n", brojac);
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
                if(s[i].provera(pticica.getPosition(), pticica.getSize(),pticica.ugao(),brojac)==0)
                    zivot = 0;
                s[i].pomeri();
            }
            printf("\nSkor: %d\n", brojac);
            if (zivot == 0)
                rezultati(&prozor,font,brojac);
            poeni(&prozor, font, brojac);

            pticica.osvezi();//gravitacija (ptica ubrzava na dole)
            pticica.crtaj();//iscrtavanje ptice

            //iscrtavanje frejma i potom njegovo brisanje
            prozor.display();
            prozor.clear();
        }
    }
	return 0;
}
