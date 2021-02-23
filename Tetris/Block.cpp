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
	y = -60;

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && SafeToMove("right"))
		activeBlocks[0]->x += 20;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && SafeToMove("left"))
		activeBlocks[0]->x -= 20;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !activeBlocks[0]->placed)
		activeBlocks[0]->y += 20;
}

// Makes block fall
void Block::Fall()
{
	if (!activeBlocks[0]->placed) {
		speed++;
		if (speed == 15)
		{
			activeBlocks[0]->y += 20;
			speed = 0;
			std::cout << std::endl << std::endl;
		}
	}
}

// Rotates block
void Block::Rotate()
{
	char changedBitmap[3][3] = { '0' };
	char tempBitmap[3][3] = { '0' };
	bool SafeToRotate = true;

	// Rotates block
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tempBitmap[i][j] = activeBlocks[0]->bitmap[3 - 1 - j][i];
		}
	}

	// Checks if place is valid
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tempBitmap[i][j] != '0') {
				if (grid[activeBlocks[0]->x / 20 + j][activeBlocks[0]->y / 20 + i] != 0) {
					SafeToRotate = false;
				}
			}
		}
	}

	// Assigns block
	if (SafeToRotate)
	{
		std::cout << "Rotated!" << std::endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				activeBlocks[0]->bitmap[i][j] = tempBitmap[i][j];
			}
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
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (activeBlocks[0]->bitmap[i][j] != '0') {
				if (grid[activeBlocks[0]->x / 20 + j][(activeBlocks[0]->y + 20) / 20 + i] != 0) {
					activeBlocks[0]->placed = true;
					return;
				}
			}
		}
	}

	activeBlocks[0]->placed = false;
}

bool Block::SafeToMove(std::string direction)
{
	if (direction == "right")
	{
		// Checks if right place is valid
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (activeBlocks[0]->bitmap[i][j] != '0') {
					if (grid[(activeBlocks[0]->x + 20) / 20 + j][activeBlocks[0]->y / 20 + i] != 0) {
						return false;
					}
				}
			}
		}
	}
	else if (direction == "left")
	{
		// Checks if left place is valid
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (activeBlocks[0]->bitmap[i][j] != '0') {
					if (grid[(activeBlocks[0]->x - 20) / 20 + j][activeBlocks[0]->y / 20 + i] != 0) {
						return false;
					}
				}
			}
		}
	}
}

// Fills 2D array
void Block::FillGrid()
{
	
}