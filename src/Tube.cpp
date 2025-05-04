#include "Tube.h"
#include "TubePos.h"
#include "obstacles/Buoy.h"
#include "obstacles/Rock.h"

#include <iostream>

Tube::Tube(sf::Vector2f position, float radius, sf::Vector2f origin, sf::Color color, float ropeLength, sf::Vector2f tubeAnchorPosition, sf::Vector2f& boatAnchorPosition) : 
	position(position), 
	radius(radius), 
	origin(origin), 
	color(color), 
	ropeLength(ropeLength),
	tubeAnchorPosition(tubeAnchorPosition),
	boatAnchorPosition(boatAnchorPosition)
{
	this->init();
}

void Tube::init()
{
	this->initRadius();
	this->initOrigin();
	this->initColor();
	this->initPos();
}

void Tube::initRadius()
{
	this->shape.setRadius(radius);
}

void Tube::initOrigin()
{
	this->shape.setOrigin(this->origin);
}

void Tube::initColor()
{
	this->shape.setFillColor(this->color);
}

void Tube::initPos()
{
	this->mouseX = this->position.x;
	this->shape.setPosition(position);
}


void Tube::update(float dt)
{
	this->position = calculateTubePos(this->mouseX, this->boatAnchorPosition, this->ropeLength);
	this->shape.setPosition(position);
	this->tubeAnchorPosition = this->position;
}

void Tube::draw(sf::RenderTarget& target) const
{
	target.draw(this->shape);
}

void Tube::onMouseMoved(int x, int y)
{
	// convert to float for
	// dx calculation, a rational value
	this->mouseX = static_cast<float>(x);
}

sf::FloatRect Tube::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Tube::onCollision(Collidable& other)
{
	// downcast to pointer (passed in a reference,
	// so double referencing to convert to pointer)
	if (dynamic_cast<Rock*>(&other))
	{
		std::cout << "Player hit rock!\n";
	}
	else if (dynamic_cast<Buoy*>(&other))
	{
		std::cout << "Player hit buoy!\n";
	}
}

sf::Vector2f& Tube::getAnchor()
{
	return this->tubeAnchorPosition;
}
