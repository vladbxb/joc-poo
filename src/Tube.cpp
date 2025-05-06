#include "Tube.h"
#include "TubePos.h"
#include "obstacles/Buoy.h"
#include "obstacles/Rock.h"

#include <iostream>

Tube::Tube(sf::Vector2f position, float radius, sf::Vector2f origin, sf::Color color, float ropeLength, sf::Vector2f tubeAnchorPosition, sf::Vector2f& boatAnchorPosition, float gameHeight, std::shared_ptr<int> lives, std::shared_ptr<int> score) : 
	position(position), 
	radius(radius), 
	origin(origin), 
	color(color), 
	ropeLength(ropeLength), tubeAnchorPosition(tubeAnchorPosition),
	boatAnchorPosition(boatAnchorPosition),
	timeSinceLastTrail(0.f),
    // trailSpawnInterval(0.1f),
	trailSpawnInterval(0.05f),
	gameHeight(gameHeight),
	lives(lives),
	score(score),
	airborne(false),
	invulnerable(false),
	timeSinceAirborne(0),
	timeAllowedInAir(1.5f),
	timeSinceInvulnerable(0),
	timeAllowedInvulnerable(2.f)
{
	this->init();
}

void Tube::init()
{
	this->initRadius();
	this->initOrigin();
	this->initColor();
	this->initPos();
}

void Tube::initRadius()
{
	float shadowRadius = this->radius * 0.75f;
	this->shape.setRadius(this->radius); // tube
	this->shadow.setRadius(shadowRadius); // shadow
}

void Tube::initOrigin()
{
	float shadowRadius = this->radius * 0.75f;
	this->shape.setOrigin(this->origin);
	this->shadow.setOrigin(sf::Vector2f(shadowRadius, shadowRadius));
}

void Tube::initColor()
{
	sf::Color shadowColor(0, 0, 0, 0);
	this->shape.setFillColor(this->color);
	this->shadow.setFillColor(shadowColor);
}

void Tube::initPos()
{
	this->mouseX = this->position.x;
	this->shape.setPosition(position);
	this->shadow.setPosition(position);
}

void Tube::jump()
{
	if (this->airborne == false)
	{
		this->showShadow();
		this->airborne = true;
	}
}

void Tube::land()
{
	if (this->airborne == true)
	{
		this->hideShadow();
		this->airborne = false;
	}
}

void Tube::showShadow()
{
	sf::Color shadowColor(0, 0, 0, 100);
	this->shadow.setFillColor(shadowColor);
}

void Tube::hideShadow()
{
	sf::Color shadowColor(0, 0, 0, 0);
	this->shadow.setFillColor(shadowColor);
}

void Tube::drawShadow(sf::RenderTarget& target) const
{
	target.draw(this->shadow);
}

void Tube::resetTrailTimeElapsed()
{
	this->timeSinceLastTrail = 0.f;
}

void Tube::handleTrailSpawn(float deltaTime)
{
	if (this->timeSinceLastTrail < this->trailSpawnInterval)
	{
		this->timeSinceLastTrail += deltaTime;
		return;
	}

	this->resetTrailTimeElapsed();

	this->spawnTrail(this->gameHeight);
	this->clearInactiveTrails();
}

void Tube::spawnTrail(float deSpawnHeight)
{
	sf::Vector2f startPosition(this->position);
	float radius = this->radius;
	sf::Color color(93, 194, 249);
	this->trails.push_back(TubeTrail(startPosition, radius, color, deSpawnHeight));
}

void Tube::clearInactiveTrails()
{
	while (this->trails.front().shouldBeDeleted())
	{
		this->trails.pop_front();
	}
}

void Tube::updateAllTrails(float deltaTime)
{
	std::deque<TubeTrail>::iterator t;
	for (t = this->trails.begin(); t != this->trails.end(); ++t)
		t->update(deltaTime);
}

void Tube::loseLife()
{
	(*lives)--;
}

void Tube::becomeInvulnerable()
{
	if (this->invulnerable == false)
	{
		this->showInvulnerability();
		this->invulnerable = true;
	}
}

void Tube::becomeVulnerable()
{
	if (this->invulnerable)
	{
		this->hideInvulnerability();
		this->invulnerable = false;
	}
}

void Tube::showInvulnerability()
{
	sf::Color transparentRed(255, 0, 0, 150);
	this->shape.setFillColor(transparentRed);
}

void Tube::hideInvulnerability()
{
	this->shape.setFillColor(sf::Color::Red);
}

bool Tube::isAirborne() const
{
	return this->airborne;
}

bool Tube::isInvulnerable() const
{
	return this->invulnerable;
}

void Tube::incrementScoreByTime()
{
	*this->score += 1;
}

void Tube::incrementScoreByJump()
{
	*this->score += 25;
}

void Tube::update(float dt)
{
	if (this->isAirborne() == false)
		this->updateOnWater(dt);
	else
		this->updateInAir(dt);

	if (this->isInvulnerable())
		this->trackInvulnerability(dt);
}

void Tube::updateOnWater(float dt)
{
	this->position = calculateTubePos(this->mouseX, this->boatAnchorPosition, this->ropeLength);
	this->shape.setPosition(position);
	this->tubeAnchorPosition = this->position;
	this->handleTrailSpawn(dt);
	this->updateAllTrails(dt);
}

void Tube::updateInAir(float dt)
{
	this->trackAirTime(dt);
	// this should move it upwards slightly
	this->position = calculateTubePosAirborne(this->mouseX, this->boatAnchorPosition, this->ropeLength);
	this->shape.setPosition(position);
	sf::Vector2f shadowPosition = calculateTubePos(this->mouseX, this->boatAnchorPosition, this->ropeLength);
	this->shadow.setPosition(shadowPosition);
	this->tubeAnchorPosition = this->position;

	// don't make any more trails
	this->resetTrailTimeElapsed();
	this->updateAllTrails(dt);
}

void Tube::trackAirTime(float dt)
{
	if (this->timeSinceAirborne < this->timeAllowedInAir)
		this->timeSinceAirborne += dt;
	else
	{
		this->resetAirTime();
		this->land();
	}
}

void Tube::resetAirTime()
{
	this->timeSinceAirborne = 0.f;
}

void Tube::trackInvulnerability(float dt)
{
	if (this->timeSinceInvulnerable < this->timeAllowedInvulnerable)
		this->timeSinceInvulnerable += dt;
	else
	{
		this->resetTimeInvulnerable();
		this->becomeVulnerable();
	}
}

void Tube::resetTimeInvulnerable()
{
	this->timeSinceInvulnerable = 0.f;
}

void Tube::draw(sf::RenderTarget& target) const
{
	this->drawShadow(target);
	target.draw(this->shape);
}

void Tube::drawAllTrails(sf::RenderTarget& target) const
{
	std::deque<TubeTrail>::const_iterator t;
	for (t = this->trails.begin(); t != this->trails.end(); ++t)
		t->draw(target);
}

void Tube::onMouseMoved(int x, int y)
{
	// convert to float for
	// dx calculation, a rational value
	this->mouseX = static_cast<float>(x);
}

sf::FloatRect Tube::getBounds() const
{
	if (this->isAirborne() == false)
		return this->shape.getGlobalBounds();
	return this->shadow.getGlobalBounds();
}

void Tube::onCollision(Collidable& other)
{
	// downcast to pointer (passed in a reference,
	// so double referencing to convert to pointer)
	if (Rock* rock = dynamic_cast<Rock*>(&other))
	{
		if (rock->isHit() == false)
		{
			if (this->isAirborne())
			{
				this->incrementScoreByJump();
				std::cout << "Player has jumped over rock!\n";
			}
			else
			{
				if (this->isInvulnerable() == false)
				{
					this->loseLife();
					this->becomeInvulnerable();
				}
				std::cout << "Player collides with rock!\n";
			}
		}
	}
	else if (Buoy* buoy = dynamic_cast<Buoy*>(&other))
	{
		if (buoy->isHit() == false)
		{
			if (this->isInvulnerable() == false)
			{
				this->loseLife();
				this->becomeInvulnerable();
			}
			std::cout << "Player collides with buoy! They can't jump over!\n";
		}
	}
}

void Tube::onMousePressed(sf::Mouse::Button, int x, int y)
{
	this->jump();
}

sf::Vector2f& Tube::getAnchor()
{
	return this->tubeAnchorPosition;
}
