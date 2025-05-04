#pragma once

#include <SFML/Graphics/Rect.hpp>

// abstract class for objects that collide
class Collidable
{
public:
	// used to grab the hitbox
	virtual sf::FloatRect getBounds() const = 0;
	// used to perform action on self after collision
	virtual void onCollision(Collidable& other) = 0;
	virtual ~Collidable() = default;
};
