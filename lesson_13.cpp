#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "include/Player.h"
#include "include/Platform.h"

static const float VIEW_HEIGHT = 512.0f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    // Load player texture.
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./textures/tux_linux_sprites.png");

    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f, 200.0f);

    std::vector<Platform> platforms;

    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        // Lock 20fps
        if (deltaTime > (1.0f / 20.0f))
        {
            deltaTime = (1.0f / 20.0f);
        }

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::Resized:
            {
                float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
                view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
                break;
            }
            }
        }

        player.Update(deltaTime);

        sf::Vector2f direction;

        for (Platform &p : platforms)
        {
            if (p.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
            {
                player.OnCollision(direction);
            }
        }

        view.setCenter(player.GetPosition());

        window.clear(sf::Color(150, 150, 150));
        window.setView(view);
        player.Draw(window);
        for (Platform &p : platforms)
        {
            p.Draw(window);
        }
        window.display();
    }

    return 0;
}