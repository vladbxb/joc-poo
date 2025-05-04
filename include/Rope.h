#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include "graphics/LineSegment.h"
#include <SFML/Graphics/Color.hpp>

class Rope : public Drawable, public Updatable
{
private:
	LineSegment ropeSegment;
	const sf::Vector2f& boatAnchorPoint;
	const sf::Vector2f& tubeAnchorPoint;
public:
	Rope(sf::Vector2f& boatAnchorPoint, sf::Vector2f& tubeAnchorPoint);

	void init();
	void initOrigin();
	void initColor();
	void initPos();
	void initRotation();

	void draw(sf::RenderTarget& target) const override;
	void update(float dt) override;
};
