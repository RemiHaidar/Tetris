#include "Game.h"

Game::Game()
{
	for (int i = 15; i < 25; i++)
	{
		grid[15][i] = 4;
	}
}

void Game::DrawGrid(sf::RenderWindow& w)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 45; j++) {
			if (grid[i][j] != 0)
			{
				b.setFillColor(colors[grid[i][j]]);
				b.setSize(sf::Vector2f(20.0f, 20.0f));
				b.setPosition(i * 20, j * 20);
				w.draw(b);
			}
		}
	}
}