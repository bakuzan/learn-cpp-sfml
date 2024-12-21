#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    player.setPosition(206.0f, 206.0f);

    // Load player texture.
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./textures/tux_linux_sprites.png");
    player.setTexture(&playerTexture);

    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3;
    textureSize.y /= 9;

    player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));

    while (window.isOpen())
    {
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

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}