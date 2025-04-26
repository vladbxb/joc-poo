#include "Tube.h"

#include "TubePos.h"

// the Tube will spawn at the same X coordinate as the 
// boat middle
// also the DEFAULT ROPE LENGTH IS 30% of the height of the game

//Tube::Tube() {}

// previous ropeLength value (18 apr): 0.35f * logicalSize.y

Tube::Tube(const sf::Vector2f boatAnchor, const sf::Vector2f& logicalSize)
	: boatAnchor(boatAnchor), ropeLength(0.5f * logicalSize.y), mouseX(boatAnchor.x)
{
	// change this later if needed
	// the radius (half width) of the tube
	this->radius = 50.f;
	this->shape.setRadius(radius);

	// set the origin to the top middle part
	// because the rope is the projection
	// to the arc of the semicircle
	//
	// JUST A TEST, DELETE AFTER
	this->shape.setOrigin(radius, radius);
	//this->shape.setOrigin(radius, 0.f);
	// sets the tube color to red
	this->shape.setFillColor(sf::Color::Red);

	// we should calculate the position of the boat
	// by taking the distance between the y coord
	// of the towing point and the y coord of the 
	// attachment point
	sf::Vector2f tubePos(this->boatAnchor.x, this->boatAnchor.y + this->ropeLength);
	this->shape.setPosition(tubePos);

}

void Tube::update(float dt)
{
	sf::Vector2f tubePos = calculateTubePos(this->mouseX, this->boatAnchor, this->ropeLength);
	this->shape.setPosition(tubePos);
}

void Tube::draw(sf::RenderTarget& target) const
{
	target.draw(this->shape);
}

// SFML gives mouse coordinates as pixel position
// in integers
void Tube::onMouseMoved(int x, int y)
{
	// we have to convert to float because we need
	// to calculate dx, a rational value
	mouseX = static_cast<float>(x);
}

sf::Vector2f Tube::getAttachmentPoint() const
{
	// the position is already set to the attachment point
	// the top middle
	return this->shape.getPosition();
}
