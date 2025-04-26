#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"
#include <memory>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

// obstacle base class (does not produce concrete objects on its own)
class Obstacle : public IDrawable, public IUpdatable
{
// each obstacle must consist of a sf::Shape
// this class should be tightly coupled to SFML
// if its update method is overridden already, it should
// be considered a pseudo concrete object
protected:
	std::unique_ptr<sf::Shape> shape;
public:
	virtual void createShape(float posX) = 0;
	void draw(sf::RenderTarget& target) const override;
	// the update method for every obstacle should not be overridden
	// (i think) because maybe certain types of obstacles behave differently
	// in terms of movement
	// void update(float deltaTime) override;
	
	// obstacle should be cloned because of obstacle templates
	// this is how spawning will work
	virtual std::unique_ptr<Obstacle> clone() const = 0;
};
