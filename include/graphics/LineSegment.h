#pragma once

#include "interfaces/Drawable.h"
#include <SFML/Graphics.hpp>

class LineSegment : public Drawable
{
private:
	sf::RectangleShape segment;
	sf::Color color;
	sf::Vector2f point1;
	sf::Vector2f point2;
	float thickness;
public:
	LineSegment();
	LineSegment(sf::Vector2f point1, sf::Vector2f point2, float thickness, sf::Color color);

	void constructSegment();
	float getRotationAngle() const;
	void draw(sf::RenderTarget& target) const override;

	void changePoint1(sf::Vector2f point);
	void changePoint2(sf::Vector2f point);
};
