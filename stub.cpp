#include "stub.h"
stub::stub()
{
    gornja = 150;
    donja = 150;
    debljina = 20;
    boja1 = sf::Color::Yellow;
    boja2 = sf::Color::Green;
}
void stub::podesi(int gornja_duzina, int donja_duzina)
{
    gornja = gornja_duzina;
    donja = donja_duzina;
}
void stub::ispis(int x, sf::RenderWindow& prozor)
{
    sf::RectangleShape pravougaonik1(sf::Vector2f(debljina, gornja));
    sf::RectangleShape pravougaonik2(sf::Vector2f(debljina, donja));
    sf::RectangleShape pravougaonik3(sf::Vector2f(debljina + 8, debljina));
    sf::RectangleShape pravougaonik4(sf::Vector2f(debljina + 8, debljina));
    pravougaonik1.setPosition(x, 0.0f);
    pravougaonik2.setPosition(x, (400.0f - donja));
    pravougaonik3.setPosition(x - 4, gornja - debljina);
    pravougaonik4.setPosition(x - 4, (400.0f - donja));
    pravougaonik1.setFillColor(boja1);
    pravougaonik2.setFillColor(boja1);
    pravougaonik3.setFillColor(boja2);
    pravougaonik4.setFillColor(boja2);
    prozor.draw(pravougaonik1);
    prozor.draw(pravougaonik2);
    prozor.draw(pravougaonik3);
    prozor.draw(pravougaonik4);
}