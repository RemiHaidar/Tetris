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
	sf::RectangleShape previewBlock;
	// int previewX, previewY;
public:
	Block();
	void Fall();
	void Move();
	void Rotate();
	void DrawBlock(sf::RenderWindow&);
	bool SafeToMove(const std::string&);
	void PlaceOnGrid(std::vector<Block*>&);
	void DisplayNextBlock(std::vector<Block*>& , sf::RenderWindow&);
	void DropBlock();
	void Preview(sf::RenderWindow&);
};