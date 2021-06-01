#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "stub.h"
#include "ptica.h"
void rezultati(sf::RenderWindow *prozor, sf::Font font,int skor,int m,std::string kom[35],int bk,std::string trk[20],int bt)
{
    sf::RectangleShape k;
    k.setSize(sf::Vector2f(prozor->getSize().x * 0.6f, prozor->getSize().y * 0.6f));
    k.setPosition(sf::Vector2f(sf::Vector2f(prozor->getSize().x * 0.2f, prozor->getSize().y * 0.2f)));
    k.setFillColor(sf::Color(1, 1, 1, 200));
    prozor->draw(k);

    sf::Text kraj, osvojeno, tip, ispkom;
    kraj.setFont(font);
    kraj.setCharacterSize(40);
    kraj.setPosition(0.38f * prozor->getSize().x, 0.25f * prozor->getSize().y);
    kraj.setString("KRAJ IGRE");
    prozor->draw(kraj); 

    osvojeno.setFont(font);
    osvojeno.setCharacterSize(30);
    osvojeno.setPosition(0.25f * prozor->getSize().x, 0.35f * prozor->getSize().y);
    std::stringstream ss;
    ss << "Osvojili ste ukupno " << skor << " poena.\nRekord: "<<(skor<m)*m+(skor>m)*skor;
    
    osvojeno.setString(ss.str().c_str());
    prozor->draw(osvojeno);

    tip.setFont(font);
    tip.setCharacterSize(25);
    tip.setString(trk[1+rand() % bt]);
    tip.setPosition(0.22f * prozor->getSize().x, 0.7f * prozor->getSize().y);
    prozor->draw(tip);

    int d;
    if (m == 0)d = 1;
    else if (skor > m)d = 2;
    else if (m - skor < 5)d = 3;
    else if (skor == 8)d = 4;
    else if (skor == 10)d = 5;
    else if (skor < 16)d = 10 + rand() % 6;
    else if (skor < 35)d = 6 + rand() % 4;
    else d = 16 + rand() % 9;
    ispkom.setFont(font);
    ispkom.setCharacterSize(28);
    ispkom.setString(kom[d]);
    std::cout << kom[d] << "\n";
    ispkom.setPosition(0.29f * prozor->getSize().x, 0.5f * prozor->getSize().y);
    prozor->draw(ispkom);
}

void poeni(sf::RenderWindow *prozor,sf::Font font, int skor,int m)
{
    sf::Text ispis;
    ispis.setFont(font);
    ispis.setCharacterSize(30);
    if(m<skor)
        ispis.setFillColor(sf::Color::Red);
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
    srand(time(NULL));
    sf::RenderWindow prozor(sf::VideoMode(800, 600), "Flappy Bird",sf::Style::Close);
    prozor.setFramerateLimit(120);
    
    sf::Texture texture1,texture2;
    sf::Sprite sprite1,sprite2;
    if (!(texture1.loadFromFile("resource/pozadina.png")))//ucitavanje pozadine
        std::cout << "Cannot load image1"<<std::endl;
    if (!(texture2.loadFromFile("resource/ptica.png")))//ucitavanje slike ptice
        std::cout << "Cannot load image2" << std::endl;
    sf::Font font;
    if (!font.loadFromFile("resource/sansation.ttf"))//ucitavanje fonta
        return EXIT_FAILURE;
    FILE* najbolji;

    int max, brk, brt;
    if ((najbolji=fopen("resource/najbolji.txt","r"))==NULL)
    {
        printf("Ne postoji najbolji upisujem 0\n");
        max = 0;
    }
    else
    {
        fscanf(najbolji, "%d", &max);
        fclose(najbolji);
    }
    std::ifstream komentari("resource/komentari.txt"),trikovi("resource/tips.txt");
    std::string komentar[35], trik[20];
    komentari >> brk;
    trikovi >> brt;
    std::cout <<"Rekord: "<< max<<" Br komentara: "<< brk<<" Br hintova: " << brt<<"\n";
    for (int i = 0; std::getline(komentari, komentar[i]) && i < brk; i++);
    for (int i = 0; std::getline(trikovi, trik[i]) && i < brt; i++);
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
			if (evnt.text.unicode == ' ')
			{
			    pticica.skok();
			    printf("Skok\n");
			}
		    }
		    break;
		default:
		    break;
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

            if (zivot == 0)
            {
                printf("Kraj igre - %d poeni\n", brojac);
                rezultati(&prozor,font,brojac,max,komentar,brk,trik,brt);//ispisuje endscreen
                if (brojac > max)
                {
                    najbolji=fopen("resource/najbolji.txt", "w");
                    fprintf(najbolji, "%d", brojac);
                    fclose(najbolji);
                    printf("Upisan novi rekord.\n");
                }
            }
            poeni(&prozor, font, brojac,max);//ispisuje br. preskocenih stubova u gornjem desnom uglu

            pticica.osvezi();//gravitacija (ptica ubrzava na dole)
            pticica.crtaj();//iscrtavanje ptice

            //iscrtavanje frejma i potom njegovo brisanje
            prozor.display();
            prozor.clear();
        }
    }
	return 0;
}
