#include "Boat.h"

Boat::Boat(const sf::Vector2f& logicalSize)
{
	// we calculate the width and height proportionally
	// to the game size
	float width = logicalSize.x * this->WIDTH_PROP;
	float height = logicalSize.y * this->HEIGHT_PROP;
	sf::Vector2f boatSize(width, height);
	// here we set the properties of the shape
	// size
	this->shape.setSize(boatSize);
	// color
	this->shape.setFillColor(sf::Color::Yellow);
	// origin is top middle
	// BE CAREFUL WITH THIS! this can break getTowingPoint()
	// if changed (or if it doesn't exist)
	this->shape.setOrigin(width / 2.f, 0.f);
	// now we declare the position, which should be
	// center, upper half, a little bit of space above
	//
	// X coordinate is at the middle of the screen 
	float posX = logicalSize.x / 2.f;
	// Y coordinate is a little bit under the "roof"
	// of the game
	float posY = logicalSize.y / 0.25f;
	sf::Vector2f boatPos(posX, posY);
	this->shape.setPosition(boatPos);
}

void Boat::draw(sf::RenderTarget& target)
{
	// we just draw the constructed shape for now
	target.draw(this->shape);
}

sf::Vector2f Boat::getTowingPoint() const
{
	// we want to return kind of the bottom middle
	// part of the boat (that's just logical)

	// let's couple this function to the sf::RectangleShape
	// for now
	
	sf::Vector2f boatPos = this->shape.getPosition();
	sf::Vector2f boatSize = this->shape.getSize();

	// now, we need to grab this part in terms of the origin
	float origin = boatSize.x / 2.f;
	// WE'RE ASSUMING THE ORIGIN WAS SET TO TOP CENTER HERE!!!
	sf::Vector2f towOffset(0.f, boatSize.y);
	// so this method depends on the origin being set correctly
	// for prototyping reasons
	return boatPos + towOffset;
}
