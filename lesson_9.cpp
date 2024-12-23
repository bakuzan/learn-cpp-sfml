#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/Animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    player.setPosition(206.0f, 206.0f);

    // Load player texture.
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./textures/tux_linux_sprites.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, sf::Vector2u(3, 8), 0.3f);
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        animation.Update(0, deltaTime);
        player.setTextureRect(animation.textureRect);

        window.clear(sf::Color(150, 150, 150));
        window.draw(player);
        window.display();
    }

    return 0;
}