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
	bool blockIsPlaced = false;
	sf::RectangleShape block;
public:
	Block();
	void Fall();
	void Move();
	void Rotate();
	void DrawBlock(sf::RenderWindow&);
	bool SafeToMove(std::string);
	void PlaceOnGrid(std::vector<Block*>&);
};