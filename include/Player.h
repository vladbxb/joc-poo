#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"
#include "Boat.h"
#include "Tube.h"
#include "Rope.h"

class Player : IDrawable, IUpdatable
{
private:
	Boat boat;
	Tube tube;
	// Rope rope;
public:
	Player(const sf::Vector2f& logicalSize);
	void update(float dt) override;
	void draw(sf::RenderTarget& target) const override;
	// temporary, only a prototype
	Tube& getTube();
};
