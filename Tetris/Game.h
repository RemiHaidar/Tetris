#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
protected:
	sf::RectangleShape b;
	//Grid
	int grid[25][45] = { 0 };
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
};