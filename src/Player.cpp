#include "Player.h"
#include "Game.h"

#include <memory>

const unsigned int STARTING_LIVES = 3;
const float PLAYER_TO_WINDOW_PROPORTION = 0.05f;
const sf::Color SHAPE_COLOR = sf::Color(255, 0, 0);
const float RELATIVE_PLAYER_POSITION = 0.85f;

Player::Player(Game& playing) : playing(playing)
{ 
	this->lives = STARTING_LIVES;
	float raza = playing.window.getSize().x * PLAYER_TO_WINDOW_PROPORTION;
	this->shape = std::make_unique<sf::CircleShape>(raza);
	this->shape->setFillColor(SHAPE_COLOR);
	this->shape->setOrigin(raza, raza);
	this->shape->setPosition(playing.window.getSize().x / 2, playing.windowDim.y * RELATIVE_PLAYER_POSITION);
}

void Player::update()
{
	float raza = playing.windowDim.x * PLAYER_TO_WINDOW_PROPORTION;
	this->shape = std::make_unique<sf::CircleShape>(raza);
	this->shape->setFillColor(SHAPE_COLOR);
	this->shape->setOrigin(raza, raza);
	this->shape->setPosition(playing.mouseCoords.x, playing.windowDim.y * RELATIVE_PLAYER_POSITION);
}

void Player::draw()
{
	playing.window.draw(*this->shape);
}
