#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
protected:
	// Rectangle used to draw grid
	sf::RectangleShape b;
	//Grid : 45 being the number of rows and 26 the number of columns
	int grid[46][26] = { 0 };
	// Fall speed
	int speed = 0;
	// Different colors
	sf::Color colors[6] = {
		sf::Color{144,255,144},
		sf::Color{0,0,255},
		sf::Color{255,255,0},
		sf::Color{255,0,255},
		sf::Color{255,165,0},
		sf::Color{255,0,0}
	};
	// Different shapes
	char shapes[7][4][3] = {
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
			{ '0', '1', '0' }	}
	};
public:
	Game();
	void DrawGrid(sf::RenderWindow&);
	void PrintGrid();
	void DrawLimits(sf::RenderWindow&);
};