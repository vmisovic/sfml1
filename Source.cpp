#include <iostream>
#include <SFML\Graphics.hpp>
#include "stub.h"
#include "ptica.h"
int main()
{
    sf::RenderWindow prozor(sf::VideoMode(800, 600), "Za mog brata Zaklopcinca!",sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape pravougaonik(sf::Vector2f(50.0f,50.0f));
    pravougaonik.setPosition(300.0f, 300.0f);
    pravougaonik.setFillColor(sf::Color::Red);
    sf::Texture texture1,texture2;
    sf::Sprite sprite1,sprite2;
    if (!(texture1.loadFromFile("pozadina.png")))
        std::cout << "Cannot load image1"<<std::endl;
    if (!(texture2.loadFromFile("ptica.png")))
        std::cout << "Cannot load image2" << std::endl;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    ptica nova(&prozor);
    int frejm=0;
    while (prozor.isOpen())
    {
        frejm++;
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
                        nova.skok();
                }
                
            }
        }
        prozor.draw(sprite1);
        stub s1(&prozor),s2(&prozor),s3(&prozor);
        s1.podesi(100, 200);
        s2.podesi(180, 120);
        s3.crtaj(100);
        s1.crtaj(200);
        s2.crtaj(300);
        nova.osvezi(frejm);
        nova.crtaj(sprite2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            pravougaonik.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            pravougaonik.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            pravougaonik.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            pravougaonik.move(0.0f, 0.1f);
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            pravougaonik.setFillColor(sf::Color::Green);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            pravougaonik.setFillColor(sf::Color::Red);
        }
        if (evnt.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel&&evnt.mouseWheelScroll.delta>0)
        {
            pravougaonik.rotate(0.1f);
        }
        if (evnt.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel && evnt.mouseWheelScroll.delta<0)
        {
            pravougaonik.rotate(-0.1f);
        }
        prozor.draw(pravougaonik);
        prozor.display();
        prozor.clear();
    }
	return 0;
}
