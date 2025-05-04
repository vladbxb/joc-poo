#pragma once

#include "interfaces/Drawable.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Boat : public Drawable
{
private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f origin;
	sf::Color color;
	sf::Vector2f anchor;
public:
	Boat(const sf::Vector2f position, const sf::Vector2f size, const sf::Vector2f origin, const sf::Color color, sf::Vector2f anchor);

	void init();
	void initSize();
	void initColor();
	void initOrigin();
	void initPos();
	void initAnchor();

	void draw(sf::RenderTarget& target) const override;

	sf::Vector2f& getAnchor();
};
