#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Collider.h>

class Platform
{
public:
    Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void Draw(sf::RenderWindow &window);
    Collider &GetCollider() { return collider; };

private:
    sf::RectangleShape body;
    Collider collider;
};

#endif // PLATFORM_H
