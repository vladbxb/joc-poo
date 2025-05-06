#include "obstacles/Obstacle.h"
#include "Player.h"

#include <iostream>

// Obstacle::Obstacle(float bottomBound, float spawnPosX) : 
// 	bottomBound(bottomBound), 
// 	spawnPosX(spawnPosX),
// 	hit(false),
// 	shouldBeDeleted(false)
// {}

void Obstacle::draw(sf::RenderTarget& target) const
{
	target.draw(*this->shape);
}

void Obstacle::initDefaultBools()
{
	this->hit = false;
	this->shouldBeDeleted = false;
}

void Obstacle::tryMarkingForDeletion()
{
	if (this->shape->getPosition().y >= bottomBound)
		this->markForDeletion();
}

void Obstacle::markForDeletion()
{
	this->hit = true;
}

bool Obstacle::isHit() const
{
	return this->hit;
}

void Obstacle::markHit()
{
	this->hit = true;
}

sf::FloatRect Obstacle::getBounds() const
{
	return this->shape->getGlobalBounds();
}

void Obstacle::onCollision(Collidable& other)
{
	this->markHit();
	if (dynamic_cast<Player*>(&other))
	{
		if (this->isHit() == false)
		{
			std::cout << "Obstacle hit player!\n";
		}
	}
}

// void Obstacle::update(float deltaTime)
// {
// 	// sf::Shape is sf::Transformable, so we can use
// 	// the built in move method for easy movement
// 	// by pixel offset
// 	// https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Transformable.php#ab9ca691522f6ddc1a40406849b87c469
// 	this->shape->move(0.f, 1.f * deltaTime); // move down 1 pixel per frame
// }
