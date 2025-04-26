#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"
#include "Boat.h"
#include "Tube.h"
#include "Rope.h"
#include "InputHandlers.h"

// using public inheritance here to treat the
// player as a whole object
// might change this later
class Player : public IDrawable, public IUpdatable
{
private:
	Boat boat;
	Tube tube;
	Rope rope;
public:
	Player(const sf::Vector2f& logicalSize);
	void update(float dt) override;
	void draw(sf::RenderTarget& target) const override;

	// this should have replaced the method below
	void addMouseDetection(MouseInputHandler& mip);
	// temporary but i don't really have any ideas
	// how to do it better
	//
	// it exists in order for the tube to be added as
	// a mouse listener
	//
	// TECHNICALLY not needed anymore because of the above
	// method (but keeping it for now just in case)
	//
	// TODO: see if this method is still needed at some point
	//
	Tube& getTube();
};
