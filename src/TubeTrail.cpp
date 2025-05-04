#include "TubeTrail.h"

TubeTrail::TubeTrail(sf::Vector2f startPosition, sf::Color color) : position(startPosition), color(color)
{
	this->init();
}

void TubeTrail::init()
{
	this->initPosition();
	this->initColor();
}

void TubeTrail::initPosition()
{
	this->trailComponent.setPosition(this->position);

void TubeTrail::initColor()
{
	this->trailComponent.setFillColor(this->color);
}

void TubeTrail::draw(sf::RenderTarget& target) const
{
	target.draw(this->trailComponent);
}

void TubeTrail::update(float deltaTime)
{
	this->moveDown(deltaTime);
}

void TubeTrail::moveDown(float deltaTime)
{
	this->trailComponent.move(0.f, 80.f * deltaTime);
}
