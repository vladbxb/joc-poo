#pragma once
// including just the RenderTarget for rendering to a window
#include <SFML/Graphics/RenderTarget.hpp>

class Drawable
{
public:
	// abstract method (needs to be overridden)
	virtual void draw(sf::RenderTarget& target) const = 0;
	// default destructor
	virtual ~Drawable() = default;
};
