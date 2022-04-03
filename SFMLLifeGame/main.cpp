#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.h"
#include "life.h"

int main()
{
    const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width, WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Life Game!", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    
    Grid grid(10, sf::Color::White, WINDOW_WIDTH, WINDOW_HEIGHT);

    Life life(15);
    life.SpawnStartCells(grid);

    float delay = 0.15f;
    sf::Clock clock;

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i position(event.mouseMove.x, event.mouseMove.y);
            position.x /= grid.GetCellSize();
            position.y /= grid.GetCellSize();
            life.SpawnCells(grid, position.x, position.y);
        }
        else
        {
            if (clock.getElapsedTime().asSeconds() >= delay)
            {
                life.CheckCells(grid);
                clock.restart();
            }
        }

        window.clear();
        grid.DrawGrid(window);
        window.display();
    }

    return 0;
}