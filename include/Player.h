#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"
#include "Boat.h"
#include "Tube.h"
#include "Rope.h"
#include "InputHandlers.h"

class Player : IDrawable, IUpdatable
{
private:
	Boat boat;
	Tube tube;
	Rope rope;
public:
	Player(const sf::Vector2f& logicalSize);
	void update(float dt) override;
	void draw(sf::RenderTarget& target) const override;

	void addMouseDetection(MouseInputHandler& mip);
	// temporary but i don't really have any ideas
	// how to do it better
	//
	// it exists in order for the tube to be added as
	// a mouse listener
	Tube& getTube();
};
