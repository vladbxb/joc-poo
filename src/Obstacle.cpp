#include "Obstacle.h"
#include <SFML/Graphics/RenderTarget.hpp>

// createShape() method doesn't have a definition here because
// it's a pure, virtual function (each "type" of obstacle should
// override it instead)

// enforcing no modification in the draw method
// not sure why, might change later
void Obstacle::draw(sf::RenderTarget& target) const
{
	target.draw(*this->shape);
}


// no longer overriding the update method
// for each obstacle no matter what it is
// void Obstacle::update(float deltaTime)
// {
// 	// sf::Shape is sf::Transformable, so we can use
// 	// the built in move method for easy movement
// 	// by pixel offset
// 	// https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Transformable.php#ab9ca691522f6ddc1a40406849b87c469
// 	this->shape->move(0.f, 1.f * deltaTime);
// }
