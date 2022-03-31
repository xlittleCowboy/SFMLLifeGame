#include <SFML/Graphics.hpp>

#include "grid.h"
#include "life.h"

int main()
{
    const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width, WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Life Game!", sf::Style::Fullscreen);
    window.setFramerateLimit(5);
    
    Grid grid(10, sf::Color::White, WINDOW_WIDTH, WINDOW_HEIGHT);

    Life life(3);
    life.SpawnStartCells(grid);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        window.clear();
        life.CheckCells(grid);
        grid.DrawGrid(window);
        window.display();
    }

    return 0;
}