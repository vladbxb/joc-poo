#pragma once

#include "buttons/RectangularButton.h"
#include <SFML/Graphics.hpp>

class RestartButton : public Drawable, public RectangularButton
{
public:
	RestartButton(sf::Vector2f position, sf::Vector2f size, bool& pressedRestart);
	void draw(sf::RenderTarget& target) const override;
private:
	bool& pressedRestart;
	sf::Font font;
	sf::Text label;
	void command(sf::Mouse::Button button) override;
};
