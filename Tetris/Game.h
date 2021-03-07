#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

class Block;

class Game
{
protected:
	// Rectangle used to draw grid
	sf::RectangleShape b;
	//Grid : 46 being the number of rows and 26 the number of columns
	static int grid[29][20];
	// Fall speed
	int speed = 0;
	// Different colors
	sf::Color colors[10] = {
		sf::Color{144,255,144},
		sf::Color{0,0,255},
		sf::Color{255,255,0},
		sf::Color{255,0,255},
		sf::Color{255,165,0},
		sf::Color{255,0,0},
		sf::Color{128,128,128},
		sf::Color{0,255,255},
		sf::Color{153,0,76},
		sf::Color{255,255,255}
	};
	// Different shapes
	char shapes[9][4][3] = {
		{	{ '0', '1', '0' },
			{ '0', '1', '0' },
			{ '0', '1', '1' }	},

		{	{ '1', '1', '0' },
			{ '0', '1', '0' },
			{ '0', '1', '1' }	},

		{	{ '0', '0', '0' },
			{ '1', '1', '1' },
			{ '0', '0', '0' }	},

		{	{ '0', '0', '0' },
			{ '1', '1', '1' },
			{ '0', '1', '0' }	},

		{	{ '1', '1', '1' },
			{ '1', '1', '1' },
			{ '1', '1', '1' }	},

		{	{ '1', '0', '0' },
			{ '1', '0', '0' },
			{ '1', '1', '1' }	},

		{	{ '0', '1', '0' },
			{ '1', '1', '1' },
			{ '0', '1', '0' }	},

		{	{ '0', '0', '0' },
			{ '0', '1', '1' },
			{ '0', '1', '1' }	},

		{	{ '1', '1', '0' },
			{ '1', '0', '0' },
			{ '1', '1', '0' }	}
	};
	sf::Font font; 
	sf::Text text;
	int rgb[3] = { 0 }, colorSpeed = 0;
	static int score;
public:
	Game();
	void DrawGrid(sf::RenderWindow&);
	void PrintGrid();
	void DrawLimits(sf::RenderWindow&);
	void InitializeGrid();
	void RemoveLineOfBlocks();
	void Lose(bool& b, std::vector<Block*>&);
	void DrawText(sf::RenderWindow&);
	void MainMenu(sf::RenderWindow&);
};