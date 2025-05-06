#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

class TubeTrail : public Drawable, public Updatable
{
private:
	sf::CircleShape trailComponent;
	sf::Vector2f position;
	float radius;
	sf::Color color;
	float deSpawnHeight;
	bool markedForDeletion;

	void markForDeletion();
	void moveDown(float deltaTime);
	bool checkOutOfBounds() const;
public:
	TubeTrail(sf::Vector2f startPosition, float radius, sf::Color color, float deSpawnHeight);

	void init();
	void initPosition();
	void initRadius();
	void initOrigin();
	void initColor();

	void tryMarkingForDeletion();
	bool shouldBeDeleted() const;

	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
};
