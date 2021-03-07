#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Button.h"
#include "Block.h"

sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris", sf::Style::Close);

Button play(200.0f,250.0f, 200.0f, 40.0f, "Play", sf::Color(107,68,35), sf::Color(255,255,0));
Button quit(200.0f, 310.0f, 200.0f, 40.0f, "Quit", sf::Color(107, 68, 35), sf::Color(255, 255, 0));
Block block;

sf::Music music;
sf::Event event;

std::vector<Block*> blocks;
bool running = false;

int main()
{
    srand(unsigned int(time(0)));
    window.setFramerateLimit(20);

    music.openFromFile("music.wav");
    music.play();

    block.InitializeGrid();

    while (window.isOpen())
    {
        window.clear();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type != sf::Event::KeyReleased && event.key.code == sf::Keyboard::W && running)
                blocks[0]->Rotate();
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space && running)
                blocks[0]->DropBlock();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                exit(0);
        }

        // Assigns new block if block is placed
        if (blocks.size() < 2)
            blocks.push_back(new Block());
        

        if (running) {

            blocks[0]->Move();
            blocks[0]->Fall();
            blocks[0]->DisplayNextBlock(blocks, window);
            blocks[0]->Preview(window);
            blocks[0]->PlaceOnGrid(blocks);
            blocks[0]->DrawBlock(window);
            blocks[0]->DrawGrid(window);
            blocks[0]->DrawLimits(window);
            blocks[0]->DrawText(window);
            blocks[0]->RemoveLineOfBlocks();
            blocks[0]->Lose(running, blocks);
        }
        else
        {
            blocks[0]->MainMenu(window);
            play.main(window, running);
            quit.main(window, running);
        }

        window.display();
    }

    return 0;
}