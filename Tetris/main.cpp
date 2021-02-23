#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Block.h"

sf::RenderWindow window(sf::VideoMode(900, 900), "Tetris", sf::Style::Close);

int main()
{
    window.setFramerateLimit(20);

    Block block;

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type != sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
                block.Rotate();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                exit(0);
        }


        block.CreateBlocks();
        block.Move();
        block.Fall();
        block.Collide();
        block.DrawGrid(window);
        block.DrawBlock(window);

        window.display();

    }

    return 0;
}