#include "buttons/PlayButton.h"

#include <string>

const std::string FONT_PATH("src/fonts/Comic_Sans_MS.ttf");

PlayButton::PlayButton(sf::Vector2f position, sf::Vector2f size, bool& pressedPlay) : RectangularButton(position, size), pressedPlay(pressedPlay)
{
	if (font.loadFromFile(FONT_PATH))
		label.setFont(font);
	else
		throw std::runtime_error("Button font could not be loaded!");

	label.setString("Joaca");
	label.setPosition(position * 0.93f);
	label.setFillColor(sf::Color::Black);
}

void PlayButton::draw(sf::RenderTarget& target) const
{
	target.draw(this->buttonShape);
	target.draw(label);
}

void PlayButton::command(sf::Mouse::Button button)
{
	pressedPlay = (button == sf::Mouse::Button::Left);
}
