#include "Player.h"

Player::Player(const sf::Vector2f& logicalSize) : 
	logicalSize(logicalSize),

	boat(this->initBoatPosition(),
		 this->initBoatSize(), 
		 this->initBoatOrigin(), 
		 this->initBoatColor(), 
		 this->initBoatAnchorPosition()),

	tube(this->initTubePosition(),
		 this->initTubeRadius(),
		 this->initTubeOrigin(),
		 this->initTubeColor(),
		 this->initRopeLength(),
		 this->initTubeAnchorPosition(),
		 this->boat.getAnchor()),

	rope(this->boat.getAnchor(),
		 this->tube.getAnchor())
{}



sf::Vector2f Player::initBoatPosition() const
{
	float width = this->logicalSize.x * 0.5f;
	float height = this->logicalSize.y * 0.05f;
	return sf::Vector2f(width, height);
}

sf::Vector2f Player::initBoatSize() const
{
	float width = this->logicalSize.x * 0.1f;
	float height = this->logicalSize.y * 0.25f;
	return sf::Vector2f(width, height);
}

sf::Vector2f Player::initBoatOrigin() const
{
	sf::Vector2f size(this->initBoatSize());
	float width = size.x * 0.5f;
	float height = 0.f;
	return sf::Vector2f(width, height);
}

sf::Color Player::initBoatColor() const
{
	return sf::Color::White;
}

sf::Vector2f Player::initBoatAnchorPosition() const
{
	sf::Vector2f boatPosition = this->initBoatPosition();
	sf::Vector2f boatSize = this->initBoatSize();
	return sf::Vector2f(boatPosition.x, boatPosition.y + boatSize.y);
}


sf::Vector2f Player::initTubePosition() const
{
	float ropeLength = this->initRopeLength();
	sf::Vector2f boatAnchorPosition = this->initBoatAnchorPosition();
	return sf::Vector2f(boatAnchorPosition.x, boatAnchorPosition.y + ropeLength);
}

float Player::initTubeRadius() const
{
	return 50.f;
}

sf::Vector2f Player::initTubeOrigin() const
{
	return sf::Vector2f(this->initTubeRadius(), this->initTubeRadius());
}

sf::Color Player::initTubeColor() const
{
	return sf::Color::Red;
}

float Player::initRopeLength() const
{
	float ropeLength = this->logicalSize.y * 0.5f;
	return ropeLength;
}

sf::Vector2f Player::initTubeAnchorPosition() const
{
	return this->initTubePosition();
}

void Player::update(float dt)
{
	this->tube.update(dt);
	this->rope.update(dt);
}

void Player::draw(sf::RenderTarget& target) const
{
	this->boat.draw(target);
	this->rope.draw(target);
	this->tube.draw(target);
}

void Player::addMouseDetection(MouseInputHandler& mip)
{
	// pass the pointer not the object itself
	mip.addListener(&this->tube);
}

sf::FloatRect Player::getBounds() const
{
	return this->tube.getBounds();
}

void Player::onCollision(Collidable& other)
{
	// pass the collision test onto the tube
	this->tube.onCollision(other);
}
