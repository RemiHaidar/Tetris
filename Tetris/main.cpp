#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Block.h"

sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris", sf::Style::Close);

Block block;

int main()
{
    srand(unsigned int(time(0)));

    std::vector<Block*> blocks;
    blocks.push_back(new Block());
    blocks[0]->InitializeGrid();

    window.setFramerateLimit(20);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type != sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
                blocks[0]->Rotate();
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                blocks[0]->DropBlock();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                exit(0);
        }

        // Assigns new block if block is placed
        if (blocks.size() < 2)
            blocks.push_back(new Block());

        blocks[0]->Move();
        blocks[0]->Fall();
        blocks[0]->DisplayNextBlock(blocks, window);
        blocks[0]->PlaceOnGrid(blocks);
        blocks[0]->DrawBlock(window);
        blocks[0]->DrawGrid(window);
        blocks[0]->DrawLimits(window);
        blocks[0]->DrawText(window);
        blocks[0]->RemoveLineOfBlocks();
        blocks[0]->Lose();

        window.display();
    }

    return 0;
}