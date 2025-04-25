#pragma once

#include <memory>
#include <SFML/Graphics/Shape.hpp>

// obstacle base class (does not produce concrete objects on its own)
class Obstacle : IDrawable, IUpdatable
{
// each obstacle must consist of a sf::Shape
// this class should be tightly coupled to SFML
// if its update method is overridden already, it should
// be considered a pseudo concrete object
protected:
	std::unique_ptr<sf::Shape> shape;
public:
	virtual void createShape() = 0;
	void update(float deltaTime) override;
};
