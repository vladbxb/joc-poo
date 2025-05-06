#include "hud/Lives.h"

#include <SFML/Graphics/Color.hpp>

// debug
#include <iostream>

void Lives::updateLives()
{
	sf::Color active(sf::Color::Green);
	sf::Color inactive(sf::Color(0, 0, 0, 0));
	switch ((*this->lives))
	{
		case 3:
		{
			this->lifeGraphics[0].setFillColor(active);
			this->lifeGraphics[1].setFillColor(active);
			this->lifeGraphics[2].setFillColor(active);
			break;
		}
		case 2:
		{
			this->lifeGraphics[0].setFillColor(active);
			this->lifeGraphics[1].setFillColor(active);
			this->lifeGraphics[2].setFillColor(inactive);
			break;
		}
		case 1:
		{
			this->lifeGraphics[0].setFillColor(active);
			this->lifeGraphics[1].setFillColor(inactive);
			this->lifeGraphics[2].setFillColor(inactive);
			break;
		}	
		case 0:
		{
			this->lifeGraphics[0].setFillColor(inactive);
			this->lifeGraphics[1].setFillColor(inactive);
			this->lifeGraphics[2].setFillColor(inactive);
			break;
		}
		default:
		{
			this->lifeGraphics[0].setFillColor(inactive);
			this->lifeGraphics[1].setFillColor(inactive);
			this->lifeGraphics[2].setFillColor(inactive);
			break;
		}
	}
}

Lives::Lives(std::shared_ptr<int> lives, sf::Vector2f position) : lives(lives), position(position), radius(35.f)
{
	this->initShapes();
}
	

void Lives::initShapes()
{
	this->initColor();
	this->initRadius();
	this->initPositions();
}

void Lives::initColor()
{
	std::array<sf::CircleShape, 3>::iterator it;
	for (it = this->lifeGraphics.begin(); it != this->lifeGraphics.end(); ++it)
		it->setFillColor(sf::Color::Green);
}

void Lives::initRadius()
{
	std::array<sf::CircleShape, 3>::iterator it;
	for (it = this->lifeGraphics.begin(); it != this->lifeGraphics.end(); ++it)
		it->setRadius(this->radius);
}

void Lives::initPositions()
{
	float diameter = this->radius * 2;
	float offset = 5.f;

	sf::Vector2f diameterVector(diameter, 0.f);
	sf::Vector2f offsetVector(offset, 0.f);

	sf::Vector2f position1 = position + offsetVector;
	sf::Vector2f position2 = position1 + diameterVector + offsetVector;
	sf::Vector2f position3 = position2 + diameterVector + offsetVector;

	// std::get<0>(this->lifeGraphics).setPosition(position1);
	// std::get<1>(this->lifeGraphics).setPosition(position2);
	// std::get<2>(this->lifeGraphics).setPosition(position3);

	this->lifeGraphics[0].setPosition(position1);
	this->lifeGraphics[1].setPosition(position2);
	this->lifeGraphics[2].setPosition(position3);
}

void Lives::draw(sf::RenderTarget& target) const
{
	std::array<sf::CircleShape, 3>::const_iterator it;
	for (it = this->lifeGraphics.begin(); it != this->lifeGraphics.end(); ++it)
		target.draw(*it);
}

void Lives::update(float deltaTime)
{
	this->updateLives();
}
