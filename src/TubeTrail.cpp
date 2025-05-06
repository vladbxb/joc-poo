#include "TubeTrail.h"

// for debugging, delete later
#include <iostream>

TubeTrail::TubeTrail(sf::Vector2f startPosition, float radius, sf::Color color, float deSpawnHeight) : 
	position(startPosition), radius(radius), color(color), deSpawnHeight(deSpawnHeight), markedForDeletion(false)
{
	this->init();
}

void TubeTrail::init()
{
	this->initPosition();
	this->initRadius();
	this->initOrigin();
	this->initColor();
}

void TubeTrail::initPosition()
{
	this->trailComponent.setPosition(this->position);
}

void TubeTrail::initOrigin()
{
	this->trailComponent.setOrigin(this->radius, this->radius);
}

void TubeTrail::initRadius()
{
	this->trailComponent.setRadius(this->radius);
}

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
	this->tryMarkingForDeletion();
}

void TubeTrail::moveDown(float deltaTime)
{
	// this->trailComponent.move(0.f, 100.f * deltaTime);
	this->trailComponent.move(0.f, 300.f * deltaTime);
}

void TubeTrail::tryMarkingForDeletion()
{
	if (this->trailComponent.getPosition().y >= this->deSpawnHeight + this->trailComponent.getRadius())
		this->markForDeletion();
}

void TubeTrail::markForDeletion()
{
	this->markedForDeletion = true;
}

bool TubeTrail::checkOutOfBounds() const
{
	return this->trailComponent.getPosition().y >= this->deSpawnHeight + this->trailComponent.getRadius();
}

bool TubeTrail::shouldBeDeleted() const
{
	return this->markedForDeletion;
}
