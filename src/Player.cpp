#include "Player.h"

Player::Player(const sf::Vector2f& logicalSize) : 
	logicalSize(logicalSize),

	lives(std::make_shared<int>(3)),

	score(std::make_shared<int>(0)),
	scoreGainInterval(1.f),
	timeElapsedScore(0.f),

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
		 this->boat.getAnchor(),
		 logicalSize.y,
		 this->lives,
		 this->score),

	rope(this->boat.getAnchor(),
		 this->tube.getAnchor()),


	playerHUD(logicalSize, this->lives, this->score)
	
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

void Player::tryIncrementingScoreByTime(float dt)
{
	if (this->timeElapsedScore < this->scoreGainInterval)
		this->timeElapsedScore += dt;
	else
	{
		this->incrementScoreByTime();
		this->resetElapsedTime();
	}
}

void Player::incrementScoreByTime()
{
	this->tube.incrementScoreByTime();
}

void Player::resetElapsedTime()
{
	this->timeElapsedScore = 0.f;
}

void Player::update(float dt)
{
	this->tryIncrementingScoreByTime(dt);
	this->tube.update(dt);
	this->rope.update(dt);
	this->playerHUD.update(dt);
}

void Player::draw(sf::RenderTarget& target) const
{
	this->boat.draw(target);
	this->rope.draw(target);
	this->tube.draw(target);
	this->playerHUD.draw(target);
}

void Player::drawAllTrails(sf::RenderTarget& target) const
{
	this->tube.drawAllTrails(target);
}

// void Player::addMouseDetection(MouseInputHandler& mip)
// {
// 	// pass the pointer not the object itself
// 	mip.addListener(&this->tube);
// }

sf::FloatRect Player::getBounds() const
{
	return this->tube.getBounds();
}

void Player::onCollision(Collidable& other)
{
	// pass the collision test onto the tube
	this->tube.onCollision(other);
}
