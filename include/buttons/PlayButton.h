#pragma once

#include "buttons/RectangularButton.h"
#include <SFML/Graphics.hpp>

class PlayButton : public Drawable, public RectangularButton
{
public:
	PlayButton(sf::Vector2f position, sf::Vector2f size, bool& pressedPlay);
	void draw(sf::RenderTarget& target) const override;
private:
	bool& pressedPlay;
	sf::Font font;
	sf::Text label;
	void command(sf::Mouse::Button button) override;
};
