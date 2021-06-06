#include "stub.h"
stub::stub()
{
    otvor = 30.f;
    visina = rand() % 60 + 5.f;
    debljina = 40;
    dx = 1;
    boja[0] = sf::Color::Yellow;
    boja[1] = sf::Color::Green;
    for (int i = 0; i < 4; i++)
    {
        pravougaonik[i].setFillColor(boja[i%2]);
        pravougaonik[i].setOutlineThickness(2);
        pravougaonik[i].setOutlineColor(sf::Color::Black);
    }
}
void stub::povezi_grafiku(sf::RenderWindow* prozor1,int x1)
{
    this->prozor = prozor1;
    x = x1;
}
void stub::podesi(double visina1, double otvor1)
{
    otvor = otvor1;
    visina = visina1;
}
void stub::crtaj()
{
    pravougaonik[0].setSize(sf::Vector2f(debljina, visina / 100.f * prozor->getSize().y));
    pravougaonik[1].setSize(sf::Vector2f(debljina + 8, debljina));
    pravougaonik[2].setSize(sf::Vector2f(debljina, (100.f - visina - otvor) / 100.f * prozor->getSize().y));
    pravougaonik[3].setSize(sf::Vector2f(debljina + 8, debljina));
    pravougaonik[0].setPosition(sf::Vector2f(x, 0.0f));
    pravougaonik[1].setPosition(sf::Vector2f(x - 4, visina / 100.f * prozor->getSize().y - debljina));
    pravougaonik[2].setPosition(sf::Vector2f(x, (visina + otvor) / 100.f * prozor->getSize().y));
    pravougaonik[3].setPosition(sf::Vector2f(x - 4, (visina + otvor) / 100.f * prozor->getSize().y));
    for(int i=0;i<4;i++) prozor->draw(pravougaonik[i]);
}
void stub::pomeri()
{
    x -= dx;
    if (x <= -50)
    {
        x = prozor->getSize().x + 150;
        podesi(rand()%60+5.f, 30.f);
    }
}
bool stub::provera(sf::Vector2f kordinate, sf::Vector2f dimenzije,double ugao,int &br)
{
    if (x + debljina == kordinate.x)
    {
        printf("Preskocen stub\n");
        br++;
    }
    if ((x > kordinate.x && x < kordinate.x + dimenzije.x) || (x + debljina > kordinate.x && x + debljina < kordinate.x + dimenzije.x))
    {
        if ((kordinate.y < (visina * prozor->getSize().y / 100.f)))
            return 0;
        if ((kordinate.y + dimenzije.y > ((visina + otvor) * prozor->getSize().y / 100.f)))
            return 0;
    }
    return 1;
}
