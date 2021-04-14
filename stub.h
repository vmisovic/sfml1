#include <SFML\Graphics.hpp>
class stub
{
    int donja, gornja, debljina;
    sf::Color boja1, boja2;
    sf::RenderWindow* prozor;
public:
    stub(sf::RenderWindow* prozor1);
    void podesi(int gornja_duz, int donja_duzina);
    void crtaj(int x);
};