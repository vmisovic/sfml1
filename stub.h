#include <SFML\Graphics.hpp>
class stub
{
    float visina, otvor, debljina;
    sf::Color boja[2];
    sf::RenderWindow* prozor;
    sf::RectangleShape pravougaonik[4];
public:
    stub();
    void povezi_grafiku(sf::RenderWindow* prozor1);
    void podesi(int visina, int otvor);
    void crtaj(int x);
};