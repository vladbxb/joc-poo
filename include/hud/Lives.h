#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>

class Lives : Drawable, Updatable
{
private:
	std::shared_ptr<int> lives;
	std::array<sf::CircleShape, 3> lifeGraphics;
	float radius;
	sf::Vector2f position;

	void initShapes();
	void initColor();
	void initRadius();
	void initPositions();

	void updateLives();
public:
	Lives(std::shared_ptr<int> lives, sf::Vector2f position);

	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
};
