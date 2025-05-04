#include "Boat.h"

Boat::Boat(const sf::Vector2f position, const sf::Vector2f size, const sf::Vector2f origin, const sf::Color color, sf::Vector2f anchor) :
	position(position),
	size(size),
	origin(origin),
	color(color),
	anchor(anchor)
{
	this->init();
}

void Boat::init()
{
	this->initSize();
	this->initColor();
	this->initOrigin();
	this->initPos();
}

void Boat::initPos()
{
	this->shape.setPosition(position);
}
void Boat::initSize()
{
	this->shape.setSize(size);
}

void Boat::initColor()
{
	this->shape.setFillColor(color);
}

void Boat::initOrigin()
{
	this->shape.setOrigin(origin);
}

void Boat::draw(sf::RenderTarget& target) const
{
	target.draw(this->shape);
}

sf::Vector2f& Boat::getAnchor()
{
	return this->anchor;
}
