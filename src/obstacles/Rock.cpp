#include "obstacles/Rock.h"

#include <memory>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

const float radius = 35.f;

// Rock::Rock(float bottomBound, float spawnPosX) : Obstacle(bottomBound, spawnPosX)
// {
// 	this->createShape();
// }

Rock::Rock()
{
	this->initDefaultBools();
	this->initShape();
	this->initColor();
	this->initOrigin();
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

void Rock::initShape()
{
	// this creates the concrete shape inside Rock
	this->shape = std::make_unique<sf::CircleShape>(radius);
}

void Rock::initColor()
{
	// color the Rock a slightly light grey
	const sf::Color color(100, 100, 100);
	this->shape->setFillColor(color);
}

void Rock::initOrigin()
{
	this->shape->setOrigin(radius / 2, 0.f);
}

void Rock::initPosition()
{
	this->shape->setPosition(this->spawnPosX, 0.f);
}

void Rock::update(float deltaTime)
{
	// moves the shape down one pixel at a time in a straight line
	// this->shape->move(0.f, 130.f * deltaTime);
	this->shape->move(0.f, 180.f * deltaTime);
}

void Rock::createShape(float bottomBound, float spawnPosX)
{
	this->bottomBound = bottomBound;
	this->spawnPosX = spawnPosX;

	this->initPosition();
}

std::unique_ptr<Obstacle> Rock::clone() const
{
	// in other words, cloning is just making another object
	// using the copy constructor on itself
	return std::make_unique<Rock>(*this);
}
