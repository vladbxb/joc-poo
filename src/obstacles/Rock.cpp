#include "obstacles/Rock.h"

#include <memory>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

// Rock::Rock(float posX)
// {
// 	this->createShape(posX);
// }

Rock::Rock()
{
	const float radius = 35.f;
	// we color the Rock a slightly light grey
	const sf::Color color(100, 100, 100);
	// this creates the concrete shape inside Rock
	this->shape = std::make_unique<sf::CircleShape>(radius);
	this->shape->setFillColor(color);
	this->shape->setOrigin(radius / 2, 0.f);
}

Rock::Rock(const Rock& other)
{
	// there's no need for downcasting, because the type of shape
	// is already known
	const sf::CircleShape* otherShape = static_cast<const sf::CircleShape*>(other.shape.get());
	// now dereferencing the cast pointer to get the actual object
	this->shape = std::make_unique<sf::CircleShape>(*otherShape);
	this->shape->setScale(other.shape->getScale().x, other.shape->getScale().y);
	this->shape->setOrigin(other.shape->getOrigin().x, other.shape->getOrigin().y);
}	

void Rock::update(float deltaTime)
{
	// moves the shape down one pixel at a time in a straight line
	this->shape->move(0.f, 80000.f * deltaTime);
}

// factory method (centralizes each obstacle type's creation)
// in terms of X coordinate
void Rock::createShape(float posX)
{
	this->shape->setPosition(posX, 0.f);
}

std::unique_ptr<Obstacle> Rock::clone() const
{
	// in other words, cloning is just making another object
	// using the copy constructor on itself
	return std::make_unique<Rock>(*this);
}
