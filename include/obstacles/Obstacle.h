#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include "interfaces/Collidable.h"
#include <memory>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Obstacle : public Drawable, public Updatable, public Collidable
{
protected:
	std::unique_ptr<sf::Shape> shape;
	bool shouldBeDeleted;
	bool hit;
	float bottomBound;
	float spawnPosX;

	void markForDeletion();
	void markHit();
	void initDefaultBools();
public:
	virtual void createShape(float bottomBound, float spawnPosX) = 0; // pure
	void draw(sf::RenderTarget& target) const override;

	void tryMarkingForDeletion();
	bool isHit() const;

	sf::FloatRect getBounds() const override;
	void onCollision(Collidable& other) override;
	// obstacle should be cloned because of obstacle templates
	// this is how spawning will work
	virtual std::unique_ptr<Obstacle> clone() const = 0;
};
