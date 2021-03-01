#pragma once

#include <ctime>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"

class Block : public Game
{
private:
	int x = 0, y = 0;
	char bitmap[3][3];
	int colorIndex = 0;
	sf::RectangleShape block;
public:
	static Block* blocks[2];
	Block();
	void CreateBlocks();
	void Fall();
	void Move();
	void Rotate();
	void DrawBlock(sf::RenderWindow&);
	bool SafeToMove(std::string);
	void PlaceOnGrid();
};