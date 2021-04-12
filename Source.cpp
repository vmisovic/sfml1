#include <iostream>
#include <SFML\Graphics.hpp>
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
            prozor.clear(); switch (evnt.type)
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
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            pravougaonik.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            pravougaonik.move(0.1f, 0.0f);
        }
        prozor.draw(pravougaonik);
        prozor.display();
        prozor.clear();
    }
	return 0;
}
