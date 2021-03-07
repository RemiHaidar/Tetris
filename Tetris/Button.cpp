#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string text, sf::Color outlineColor, sf::Color centerColor)
{
	this->y = y; this->x = x;
	this->width = width; this->height = height;
	this->text.setString(text);
	this->outlineColor = outlineColor;
	this->centerColor = centerColor;

	button.setSize(sf::Vector2f(x, y));
	button.setSize(sf::Vector2f(width, height));
	button.setFillColor(centerColor);
	button.setOutlineColor(outlineColor);
	button.setOutlineThickness(5);
	button.setPosition(x, y);

	rect.height = height; rect.width = width;
	rect.left = x; rect.top = y;

	font.loadFromFile("arial.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(24);
	this->text.setStyle(sf::Text::Bold);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(x + 75,y + 5);
}


void Button::Draw(sf::RenderWindow& w)
{
	w.draw(button);
}


bool Button::MouseHover(sf::RenderWindow& w)
{
	if (rect.contains(sf::Mouse::getPosition().x - w.getPosition().x - 10, sf::Mouse::getPosition().y - 30 - w.getPosition().y))
		return true;
	else
		return false;
}


void Button::Click(bool& b)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && text.getString() == "Play")
		b = true;
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && text.getString() == "Quit")
		exit(0);
}

void Button::main(sf::RenderWindow& w, bool& b)
{
	if (MouseHover(w))
	{
		button.setFillColor(sf::Color(0, 0, 255));
		Click(b);
	}
	else
		button.setFillColor(centerColor);

	w.draw(button);
	w.draw(text);
}
