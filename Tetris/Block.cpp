#include "Block.h"

Block::Block() {
	// Random seed
	srand(unsigned int(time(0)));

	// Set block attributes
	colorIndex = rand() % 10;
	block.setFillColor(colors[colorIndex]);
	block.setSize(sf::Vector2f(20.0f, 20.0f));

	// Assigns random shape
	int temp = rand() % 9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bitmap[i][j] = shapes[temp][i][j];
		}
	}

	// Assigns coords
	x = 200;
	y = 0;

	previewBlock.setSize(sf::Vector2f(20.0f, 20.0f));
	previewBlock.setFillColor(sf::Color(255, 0, 0, 25));
	previewBlock.setOutlineThickness(1);
	previewBlock.setOutlineColor(sf::Color(255, 0, 0));
}

void Block::Fall()
{
	if (SafeToMove("down") && !blockIsPlaced) {
		speed++;
		if (speed == 15) {
			y += 20;
			speed = 0;
		}
	}
}

void Block::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && SafeToMove("right")) {
		x += 20;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && SafeToMove("left")) {
		x -= 20;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && SafeToMove("down")) {
		y += 20;
	}
}

void Block::DropBlock()
{
	while (SafeToMove("down"))
	{
		y += 20;
	}
}


void Block::Preview(sf::RenderWindow& w)
{
	int previewX = x, previewY = y;
	bool temp = false;

	while (true)
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[previewY / 20 + i + 1][(previewX - 20) / 20 + j] != -1) {
						temp = true;
					}
				}
			}
			
		}

		if (!temp)
			previewY += 20;
		else
			break;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (bitmap[i][j] != '0') {
				previewBlock.setPosition(previewX + (j * 20.0f), previewY + (i * 20.0f));
				w.draw(previewBlock);
			}
		}
	}
}


bool Block::SafeToMove(const std::string& direction)
{
	if (direction == "right") {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[y / 20 + i][x / 20 + j] != -1) {
						return false;
					}
				}
			}
		}
	}
	else if (direction == "left") {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[y / 20 + i][(x - 20) / 20 + j - 1] != -1) {
						return false;
					}
				}
			}
		}
	}
	else if (direction == "down") {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					if (grid[y / 20 + i + 1][(x - 20) / 20 + j] != -1) {
						blockIsPlaced = true;
						return false;
					}
				}
			}
		}
	}
	return true;
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
				if (grid[y / 20 + i][(x - 20) / 20 + j] != -1) {
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

void Block::PlaceOnGrid(std::vector<Block*>& v)
{
	if (blockIsPlaced) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bitmap[i][j] != '0') {
					grid[y / 20 + i][(x - 20) / 20 + j] = colorIndex;
				}
			}
		}
		v.erase(v.begin());
		score++;
	}
}

void Block::DisplayNextBlock(std::vector<Block*>& v, sf::RenderWindow& w)
{
	sf::RectangleShape rectangle(sf::Vector2f(167.f, 120.f));

	rectangle.setPosition(427, 120);
	rectangle.setFillColor(sf::Color{255,255,255,0});
	rectangle.setOutlineThickness(2);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[1]->bitmap[i][j] != '0') {
				v[1]->block.setPosition(480 + (j * 20.0f), 160 + (i * 20.0f));
				w.draw(v[1]->block);
			}
		}
	}

	w.draw(rectangle);
}