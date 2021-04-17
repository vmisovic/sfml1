#include <iostream>
#include <SFML\Graphics.hpp>
#include "stub.h"
#include "ptica.h"
int main()
{
    sf::RenderWindow prozor(sf::VideoMode(800, 600), "Za mog brata Zaklopcinca!",sf::Style::Close | sf::Style::Resize);
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
    ptica pticica(&sprite2,&prozor);
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
            case sf::Event::Resized:
                std::cout << evnt.size.width<< " "<<evnt.size.height<<std::endl;
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
        prozor.draw(sprite1);
        stub s[10];
        for (int i = 0; i < 10; i++)
            s[i].povezi_grafiku(&prozor);
        s[1].podesi(50, 10);
        s[2].podesi(10,80);
        s[3].crtaj(100);
        s[1].crtaj(200);
        s[2].crtaj(300);
        pticica.osvezi();
        pticica.crtaj();
        prozor.display();
        prozor.clear();
    }
	return 0;
}
