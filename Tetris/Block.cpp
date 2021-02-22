#include "Block.h"

std::vector<Block*> Block::activeBlocks;

// Constructor of class Block
Block::Block()
{
	srand(time(0));

	// Assigns block
	int temp = rand() % 7;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bitmap[i][j] = shapes[temp][i][j];
		}
	}

	// Assigns color
	colorIndex = rand() % 6;
	// Sets random y coord
	x = ((rand() % 500) / 20) * 20;

	// Sets block color and position
	block.setSize(sf::Vector2f(20,20));
	block.setFillColor(colors[colorIndex]);
}

void Block::CreateBlocks()
{
	if (activeBlocks.size() < 2)
		activeBlocks.push_back(new Block());
}

// Moves block
void Block::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		activeBlocks[0]->x += 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		activeBlocks[0]->x -= 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		activeBlocks[0]->y += 20;
	}
}

// Makes block fall
void Block::Fall()
{
	speed++;
	if (speed == 15)
	{
		activeBlocks[0]->y += 20;
		speed = 0;
		std::cout << "X : " << activeBlocks[0]->x << " | Y : " << activeBlocks[0]->y << std::endl;
		std::cout << std::endl << std::endl;
	}
}

// Rotates block
void Block::Rotate()
{
	char changedBitmap[3][3] = { '0' };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			changedBitmap[i][j] = activeBlocks[0]->bitmap[3 - 1 - j][i];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			activeBlocks[0]->bitmap[i][j] = changedBitmap[i][j];
		}
	}
}

void Block::DrawBlock(sf::RenderWindow& w)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (activeBlocks[0]->bitmap[j][i] == '1') {
				activeBlocks[0]->block.setPosition(activeBlocks[0]->x + (i * 20), activeBlocks[0]->y + (j * 20));
				w.draw(activeBlocks[0]->block);
			}
		}
	}
}


// Checks for collision
void Block::Collide()
{
		
}

// Fills 2D array
void Block::FillArray()
{
	
}