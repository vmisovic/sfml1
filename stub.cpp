#include "stub.h"
stub::stub(sf::RenderWindow* prozor1)
{
    gornja = 200;
    donja = 200;
    debljina = 40;
    boja1 = sf::Color::Yellow;
    boja2 = sf::Color::Green;
    this->prozor = prozor1;
}
void stub::podesi(int gornja_duzina, int donja_duzina)
{
    gornja = gornja_duzina;
    donja = donja_duzina;
}
void stub::crtaj(int x)
{
    sf::RectangleShape pravougaonik1(sf::Vector2f(debljina, gornja));
    sf::RectangleShape pravougaonik2(sf::Vector2f(debljina, donja));
    sf::RectangleShape pravougaonik3(sf::Vector2f(debljina*1.2f, debljina));
    sf::RectangleShape pravougaonik4(sf::Vector2f(debljina*1.2f, debljina));
    pravougaonik1.setPosition(x, 0.0f);
    pravougaonik2.setPosition(x, (prozor->getSize().y - donja));
    pravougaonik3.setPosition(x - debljina * 0.1f, gornja - debljina);
    pravougaonik4.setPosition(x - debljina * 0.1f, (prozor->getSize().y - donja));
    pravougaonik1.setFillColor(boja1);
    pravougaonik2.setFillColor(boja1);
    pravougaonik3.setFillColor(boja2);
    pravougaonik4.setFillColor(boja2);
    pravougaonik1.setOutlineThickness(2);
    pravougaonik2.setOutlineThickness(2);
    pravougaonik3.setOutlineThickness(2);
    pravougaonik4.setOutlineThickness(2);
    pravougaonik1.setOutlineColor(sf::Color::Black);
    pravougaonik1.setOutlineColor(sf::Color::Black);
    pravougaonik2.setOutlineColor(sf::Color::Black);
    pravougaonik3.setOutlineColor(sf::Color::Black);
    pravougaonik4.setOutlineColor(sf::Color::Black);
    prozor->draw(pravougaonik1);
    prozor->draw(pravougaonik2);
    prozor->draw(pravougaonik3);
    prozor->draw(pravougaonik4);
}