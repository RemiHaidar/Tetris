#include "Game.h"

int Game::grid[46][26];

Game::Game() {

	// Set grid side limits
	for (int i = 0; i < 46; i++) {
		grid[i][25] = 6;
		grid[i][0] = 6;
	}

	// Set grid bottom limit
	for (int i = 0; i < 26; i++) {
		grid[45][i] = 6;
	}
}

void Game::DrawGrid(sf::RenderWindow& w)
{
	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 26; j++) {
			if (grid[i][j] != -1) {
				b.setFillColor(colors[grid[i][j]]);
				b.setSize(sf::Vector2f(20.0f, 20.0f));
				b.setPosition(j * 20.0f + 140, i * 20.0f);
				w.draw(b);
			}
		}
	}
}

void Game::InitializeGrid()
{
	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 26; j++) {
			grid[i][j] = -1;
		}
	}
}

void Game::PrintGrid()
{
	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 26; j++) {
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Game::DrawLimits(sf::RenderWindow& w)
{
	sf::VertexArray leftLines(sf::LinesStrip, 2);
	leftLines[0].position = sf::Vector2f(160, 0);
	leftLines[1].position = sf::Vector2f(160, 900);

	sf::VertexArray rightLines(sf::LinesStrip, 2);
	rightLines[0].position = sf::Vector2f(640, 0);
	rightLines[1].position = sf::Vector2f(640, 900);

	w.draw(leftLines);
	w.draw(rightLines);
}