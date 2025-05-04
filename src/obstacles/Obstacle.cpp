#include "obstacles/Obstacle.h"
#include "Player.h"

#include <iostream>

// createShape() method doesn't have a definition here because
// it's a pure, virtual function (each "type" of obstacle should
// override it instead)

void Obstacle::draw(sf::RenderTarget& target) const
{
	target.draw(*this->shape);
}

sf::FloatRect Obstacle::getBounds() const
{
	return this->shape->getGlobalBounds();
}

void Obstacle::onCollision(Collidable& other)
{
	if (dynamic_cast<Player*>(&other))
	{
		std::cout << "Obstacle hit player!\n";
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
