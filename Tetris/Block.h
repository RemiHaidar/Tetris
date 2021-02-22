#pragma once

#include <ctime>
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

class Block : public Game
{
private:
	int x, y = 0;
	char bitmap[3][3];
	int speed = 0;
	int colorIndex;
	sf::RectangleShape block;
public:
	static std::vector<Block*> activeBlocks;
	Block();
	void CreateBlocks();
	void Fall();
	void Move();
	void Rotate();
	void DrawBlock(sf::RenderWindow&);
	void Collide();
	void FillArray();
};