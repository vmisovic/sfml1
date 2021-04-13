#include <iostream>
#include <SFML\Graphics.hpp>
#include "stub.h"
int main()
{
    sf::RenderWindow prozor(sf::VideoMode(400, 400), "Za mog brata Zaklopcinca!",sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape pravougaonik(sf::Vector2f(100.0f,100.0f));
    pravougaonik.setFillColor(sf::Color::Red);
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
                    printf("%c", evnt.text.unicode);
            }
        }
        stub s1;
        stub s2;
        s2.podesi(100, 200);
        s1.ispis(100, prozor);
        s2.ispis(220, prozor);
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
