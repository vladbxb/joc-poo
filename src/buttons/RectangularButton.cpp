#include "buttons/RectangularButton.h"

const sf::Color DEFAULT_BUTTON_COLOR(245, 236, 66);

RectangularButton::RectangularButton(sf::Vector2f position, sf::Vector2f size) : buttonShape(size)
{
	buttonShape.setOrigin(size.x / 2, size.y / 2);
	buttonShape.setPosition(position);
	buttonShape.setFillColor(DEFAULT_BUTTON_COLOR);
}
