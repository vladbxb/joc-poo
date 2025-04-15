#pragma once

#include "IDrawable.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// the boat sitting at the top of the screen!
// it's only drawable, it doesn't have to update.
// it's not dynamic, it stays still

class Boat : public IDrawable
{
private:
	// at the moment it's just made of a rectangle
	sf::RectangleShape shape;
	// the proportions in relation to the game size
	const float WIDTH_PROP = 0.1f;
	const float HEIGHT_PROP = 0.2f;

	// sf::Vector2f anchorPoint;
public:
	// the constructor
	// which will receive the logical size
	// by logical size i mean the game size
	// (not the window size) because the game
	// has a static size set
	Boat(const sf::Vector2f& logicalSize);

	// we're inheriting from IDrawable so we must
	// have a draw method
	void draw(sf::RenderTarget& target) const override;

	// this is a helper function for the Rope to easily
	// access the coordinates of the end that sticks to the
	// boat!
	sf::Vector2f getAnchorPoint() const;
};
