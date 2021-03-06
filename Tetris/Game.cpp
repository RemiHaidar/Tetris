#include "Game.h"

int Game::grid[29][20];
int Game::score = 0;

Game::Game() {

	// Set grid side limits
	for (int i = 0; i < 29; i++) {
		grid[i][19] = 6;
		grid[i][0] = 6;
	}

	// Set grid bottom limit
	for (int i = 0; i < 20; i++) {
		grid[28][i] = 6;
	}

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
}

void Game::DrawGrid(sf::RenderWindow& w)
{
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 20; j++) {
			if (grid[i][j] != -1) {
				b.setFillColor(colors[grid[i][j]]);
				b.setSize(sf::Vector2f(20.0f, 20.0f));
				b.setPosition(j * 20.0f + 20, i * 20.0f);
				w.draw(b);
			}
		}
	}
}

void Game::InitializeGrid()
{
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 20; j++) {
			grid[i][j] = -1;
		}
	}
}

void Game::PrintGrid()
{
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Game::DrawLimits(sf::RenderWindow& w)
{
	sf::VertexArray line(sf::LinesStrip, 2);
	line[0].position = sf::Vector2f(0, 40);
	line[0].color = sf::Color{ 255,0,0 };
	line[1].position = sf::Vector2f(440, 40);
	line[1].color = sf::Color{ 255,0,0 };

	text.setString("LIMIT");
	text.setPosition(sf::Vector2f(470, 25));

	w.draw(text);
	w.draw(line);
}

void Game::DrawText(sf::RenderWindow& w)
{
	text.setString("NEXT BLOCK");
	text.setPosition(sf::Vector2f(430, 120));

	w.draw(text);

	text.setString("Score: " + std::to_string(score));
	text.setPosition(sf::Vector2f(460, 300));

	w.draw(text);
}

void Game::RemoveLineOfBlocks()
{
	int tempGrid[29][20];

	for (int i = 0; i < 28; i++) {
		bool lineIsFull = true;
		for (int j = 0; j < 20; j++) {
			if (grid[i][j] == -1)
				lineIsFull = false;
		}
		if (lineIsFull)
		{
			for (int k = 0; k < 20; k++) {
				grid[i][k] = -1;
			}

			for (int x = 0; x < 29; x++) {
				for (int y = 0; y < 20; y++) {
					tempGrid[x][y] = grid[x][y];
				}
			}

			for (int x = 0; x < i; x++) {
				for (int y = 0; y < 20; y++) {
					tempGrid[x + 1][y] = grid[x][y];
				}
			}

			for (int x = 0; x < 29; x++) {
				for (int y = 0; y < 20; y++) {
					grid[x][y] = tempGrid[x][y];
				}
			}

			score += 5;
		}
	}
}

void Game::Lose()
{
	for (int i = 1; i < 19; i++) {
		if (grid[1][i] != -1)
			exit(0);
	}
}