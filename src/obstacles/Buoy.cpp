#include "obstacles/Buoy.h"

#include <memory>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

// FOR DEBUGGING
#include <iostream>

// the reason this is commented is in the Buoy.h file
// Buoy::Buoy(float posX)
// {
// 	this->createShape(posX);
// }



Buoy::Buoy()
{
	const float radius = 30.f;
	const sf::Color color(sf::Color::Yellow);
	// this creates the concrete shape inside Buoy
	this->shape = std::make_unique<sf::CircleShape>(radius);
	this->shape->setFillColor(color);
	// the Buoy shall be an ellipse (oval)
	this->shape->setScale(1.f, 2.f);
	this->shape->setOrigin(radius / 2, 0.f);
}

Buoy::Buoy(const Buoy& other)
{
	// there's no need for downcasting, because the type of shape
	// is already known
	const sf::CircleShape* otherShape = static_cast<sf::CircleShape*>(other.shape.get());
	// now dereferencing the cast pointer to get the actual object
	this->shape = std::make_unique<sf::CircleShape>(*otherShape);
	this->shape->setScale(other.shape->getScale().x, other.shape->getScale().y);
	this->shape->setOrigin(other.shape->getOrigin().x, other.shape->getOrigin().y);
}

void Buoy::update(float deltaTime)
{
	// moves the shape down one pixel at a time in a straight line
	this->shape->move(0.f, 140.f * deltaTime);
	// std::cout << "Buoy moved at: " << this->shape->getPosition().y << '\n';
}

// factory method (centralizes each obstacle type's creation)
// in terms of X coordinate
void Buoy::createShape(float posX)
{
	this->shape->setPosition(posX, 0.f);
}

std::unique_ptr<Obstacle> Buoy::clone() const
{
	// in other words, cloning is just making another object
	// using the copy constructor on itself
	return std::make_unique<Buoy>(*this);
}
