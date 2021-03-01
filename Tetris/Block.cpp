#include "Block.h"

Block* Block::blocks[2];

Block::Block() {
	// Random seed
	srand(unsigned int(time(0)));

	// Set block attributes
	block.setFillColor(colors[rand() % 6]);
	block.setSize(sf::Vector2f(20.0f, 20.0f));

	// Assigns random shape
	int temp = rand() % 7;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bitmap[i][j] = shapes[temp][i][j];
		}
	}

	// Assigns coords
	x = 380;
	y = 0;
}


void Block::CreateBlocks()
{
	// Assigns new block if block is placed
	if (blocks[0] == NULL)
	{
		blocks[0] = blocks[1];
		blocks[1] = new Block();
	}
}


void Block::Fall()
{
	speed++;
	if (speed == 15) {
		y += 20;
		speed = 0;
	}
}

void Block::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && SafeToMove("right")) {
		x += 20;
		// std::cout << x << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && SafeToMove("left")) {
		x -= 20;
		// std::cout << blocks[0]->x << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y += 20;
		// std::cout << y << std::endl;
	}
}


bool Block::SafeToMove(std::string direction)
{
	if (direction == "right") {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[y / 20 + i][(x - 120) / 20 + j] != 0) {
						return false;
					}
				}
			}
		}
		return true;
	}
	else if (direction == "left") {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[y / 20 + i][(x - 140) / 20 + j - 1] != 0) {
						return false;
					}
				}
			}
		}
		return true;
	}

	return false;
}


void Block::Rotate()
{
	char tempBitmap[3][3] = { '0' };

	// Rotates block
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tempBitmap[i][j] = bitmap[3 - 1 - j][i];
		}
	}

	bool safeToRotate = true;

	// Checks if it is safe to rotate
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tempBitmap[i][j] != '0') {
				if (grid[y / 20 + i][(x - 140) / 20 + j] != 0) {
					safeToRotate = false;
				}
			}
		}
	}

	// Commits rotation if it is safe to rotate
	if (safeToRotate) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				bitmap[i][j] = tempBitmap[i][j];
			}
		}
	}
}

void Block::DrawBlock(sf::RenderWindow& w)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (bitmap[i][j] != '0') {
				block.setPosition(x + (j * 20.0f), y + (i * 20.0f));
				w.draw(block);
			}
		}
	}
}

void Block::PlaceOnGrid()
{

}