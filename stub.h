#include <SFML/Graphics.hpp>
class stub
{
    float visina, otvor, debljina;
    int x,dx;
    sf::Color boja[2];
    sf::RenderWindow* prozor;
    sf::RectangleShape pravougaonik[4];
public:
    stub();
    void povezi_grafiku(sf::RenderWindow* prozor1,int x1);
    void podesi(double visina, double otvor);
    void crtaj();
    void pomeri();
    bool provera(sf::Vector2f kordinate,sf::Vector2f dimenzije,double ugao,int &br);
};