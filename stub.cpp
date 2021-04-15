#include "stub.h"
stub::stub()
{
    otvor = 50.f;
    visina = 25.0f;
    debljina = 40;
    boja[0] = sf::Color::Yellow;
    boja[1] = sf::Color::Green;
    for (int i = 0; i < 4; i++)
    {
        pravougaonik[i].setFillColor(boja[i%2]);
        pravougaonik[i].setOutlineThickness(2);
        pravougaonik[i].setOutlineColor(sf::Color::Black);
    }
}
void stub::povezi_grafiku(sf::RenderWindow* prozor1)
{
    this->prozor = prozor1;
}
void stub::podesi(int visina1, int otvor1)
{
    otvor = otvor1;
    visina = visina1;
}
void stub::crtaj(int x)
{
    pravougaonik[0].setSize(sf::Vector2f(debljina, visina / 100.f * prozor->getSize().y));
    pravougaonik[1].setSize(sf::Vector2f(debljina + 8, debljina));
    pravougaonik[2].setSize(sf::Vector2f(debljina, (100.f - visina - otvor) / 100.f * prozor->getSize().y));
    pravougaonik[3].setSize(sf::Vector2f(debljina + 8, debljina));
    pravougaonik[0].setPosition(sf::Vector2f(x, 0.0f));
    pravougaonik[1].setPosition(sf::Vector2f(x - 4, visina / 100.f * prozor->getSize().y - debljina));
    pravougaonik[2].setPosition(sf::Vector2f(x, (visina + otvor) / 100.f * prozor->getSize().y));
    pravougaonik[3].setPosition(sf::Vector2f(x - 4, (visina + otvor) / 100.f * prozor->getSize().y));
    for(int i=0;i<4;i++)
        prozor->draw(pravougaonik[i]);
}