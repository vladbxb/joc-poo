#include "Tube.h"

// for trigonometry
#include <cmath>

// helper function for keeping a value between bounds
float clamp(float value, float leftLim, float rightLim)
{
	if (value < leftLim)
		return leftLim;
	else
		if (value > rightLim)
			return rightLim;
	return value;
}

// the Tube will spawn at the same X coordinate as the 
// boat middle
// also the DEFAULT ROPE LENGTH IS 30% of the height of the game

//Tube::Tube() {}

Tube::Tube(const sf::Vector2f& boatAnchor, const sf::Vector2f& logicalSize)
	: boatAnchor(boatAnchor), ropeLength(0.35f * logicalSize.y), mouseX(boatAnchor.x)
{
	// change this later if needed
	this->radius = 50.f;
	this->shape.setRadius(radius);

	// set the origin to the top middle part
	// because the rope is the projection
	// to the arc of the semicircle
	this->shape.setOrigin(radius, 0.f);
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
	// this is the distance from the anchor point to
	// the anchor point
	float dx = this->mouseX - this->boatAnchor.x;
	// these are the movement bounds for the circle
	// in actual tubing the tube can never be
	// as far as the boat, so this is why it's here
	float leftLim = -this->ropeLength * 0.8f;
	float rightLim = this->ropeLength * 0.8f;
	// now force it within these bounds
	dx = clamp(dx, leftLim, rightLim);
	float ratio = dx / ropeLength;
	ratio = clamp(ratio, -1.f, 1.f);

	float angle = std::asin(ratio);
	
	// calculate the angle (A^ in my drawing)
	//float angle = std::asin(clamp(dx / ropeLength, -1.f, 1.f));

	// these formulas were derived from sketching...
	// maybe i should save them
	float x = boatAnchor.x + ropeLength * std::sin(angle);

	float y = boatAnchor.y + ropeLength * std::cos(angle);

	sf::Vector2f tubePos(x, y);
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
void Tube::setAnchorPoint(const sf::Vector2f& point) {
    this->boatAnchor = point;
}
