#pragma once

#include "interfaces/Button.h"
#include "interfaces/Drawable.h"
#include <SFML/Graphics.hpp>

class RectangularButton : public Button
{
public:
	RectangularButton(sf::Vector2f position, sf::Vector2f size);
protected:
	sf::RectangleShape buttonShape;
	virtual void command(sf::Mouse::Button button) override = 0;
	bool clickedInside(int x, int y) override
	{
		return buttonShape.getGlobalBounds().contains(static_cast<float>(x), static_cast<float>(y));
	}
};
