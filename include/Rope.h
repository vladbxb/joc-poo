#pragma once

// the rope just needs to be drawable,
// its coordinates are updated by the boat
// and tube themselves

#include "IDrawable.h"
#include <SFML/Graphics/Color.hpp>

class Rope : public IDrawable
{
private:
	// we basically just use the references
	// to the anchor point and attachment point
	// so it's easy to update
	// const sf::Vector2f start;
	// const sf::Vector2f end;
	sf::Vector2f start;
	sf::Vector2f end;
	const sf::Color ROPE_COLOR;
	const float ROPE_WIDTH;
	const float PI;
public:
	Rope(const sf::Vector2f start, const sf::Vector2f end);
	// draw overridden abstract method from IDrawable
	void draw(sf::RenderTarget& target) const override;
	void update(sf::Vector2f start, sf::Vector2f end);
};
