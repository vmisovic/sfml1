#pragma once
#include <SFML\Graphics.hpp>
class stub
{
    int donja, gornja, debljina;
    sf::Color boja1, boja2;
public:
    stub();
    void podesi(int gornja_duz, int donja_duzina);
    void ispis(int x, sf::RenderWindow& prozor);
};