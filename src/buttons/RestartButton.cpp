#include "buttons/RestartButton.h"

#include <string>
#include <iostream>

const std::string FONT_PATH("src/fonts/Comic_Sans_MS.ttf");

RestartButton::RestartButton(sf::Vector2f position, sf::Vector2f size, bool& pressedRestart) : RectangularButton(position, size), pressedRestart(pressedRestart)
{
	if (font.loadFromFile(FONT_PATH))
		label.setFont(font);
	else
		throw std::runtime_error("Button font could not be loaded!");

	label.setString("Inapoi la inceput");
	label.setPosition(position * 0.93f);
	label.setFillColor(sf::Color::Black);
}

void RestartButton::draw(sf::RenderTarget& target) const
{
	target.draw(this->buttonShape);
	target.draw(label);
}

void RestartButton::command(sf::Mouse::Button button)
{
	pressedRestart = (button == sf::Mouse::Button::Left);
}
