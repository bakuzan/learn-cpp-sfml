#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

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
            case sf::Event::Resized:
                // std::cout << "Window: " << evnt.size.width << "x" << evnt.size.height << std::endl;
                printf("Window: %ix%i\n", evnt.size.width, evnt.size.height);
                break;
            }
        }
    }

    return 0;
}