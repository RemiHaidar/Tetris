#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
private:
	sf::RectangleShape button;
	sf::FloatRect rect;
	float x, y, width, height;
	sf::Color outlineColor, centerColor;
	sf::Font font;
	sf::Text text;
	void Draw(sf::RenderWindow&);
	bool MouseHover(sf::RenderWindow&);
	void Click(bool&);
public:
	Button(float, float, float, float, std::string, sf::Color, sf::Color);
	void main(sf::RenderWindow&, bool&);
};

