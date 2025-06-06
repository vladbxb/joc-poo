#include "obstacles/ObstacleSpawner.h"

#include <exception>
#include <random>

// WARNING: the spawn interval must be set manually with the setter
ObstacleSpawner::ObstacleSpawner(const std::vector<std::unique_ptr<Obstacle>>& obstacleTemplate, float leftLim, float rightLim, float bottomBound) : 
	obstacleTemplate(obstacleTemplate), 
	rng(std::random_device{}()), 
	timeSinceLastSpawn(0.f), 
	spawnInterval(0.f), 
	leftLim(leftLim), 
	rightLim(rightLim),
	bottomBound(bottomBound)
{}

std::unique_ptr<Obstacle> ObstacleSpawner::trySpawning(float deltaTime)
{
	if (this->timeSinceLastSpawn < this->spawnInterval)
	{
		// if not enough time has elapsed, don't spawn
		// and increase the time
		this->timeSinceLastSpawn += deltaTime;
		return nullptr;
	}

	return this->spawn();
}

void ObstacleSpawner::testTemplateEmptiness() const
{
	if (this->obstacleTemplate.empty())
		throw std::runtime_error("Obstacle template is empty!");
}

void ObstacleSpawner::resetElapsedTime()
{
	this->timeSinceLastSpawn = 0.f;
}

std::unique_ptr<Obstacle> ObstacleSpawner::spawn()
{
	this->resetElapsedTime();
	std::unique_ptr<Obstacle> spawned = this->cloneRandomObstacle();
	int posX = this->getRandomXValue(this->leftLim, this->rightLim);
	spawned->createShape(this->bottomBound, posX);
	return spawned;
}

int ObstacleSpawner::getRandomIndex()
{
	int templateSizeToInt = static_cast<int>(this->obstacleTemplate.size() - 1);
	std::uniform_int_distribution<int> distrib(0, templateSizeToInt);
	int index = distrib(this->rng);
	return index;
}

int ObstacleSpawner::getRandomXValue(float leftLim, float rightLim)
{
	// generate a random X value for the obstacle to spawn
	std::uniform_int_distribution<int> posXDistrib(leftLim, rightLim);
	int posX = posXDistrib(this->rng);
	return posX;
}

std::unique_ptr<Obstacle> ObstacleSpawner::cloneRandomObstacle()
{
	int index = this->getRandomIndex();
	std::unique_ptr<Obstacle> spawned = this->obstacleTemplate[index]->clone();
	return spawned;
}

void ObstacleSpawner::setSpawnInterval(float spawnInterval)
{
	if (spawnInterval < 0)
	{
		// an exception should also be thrown here
		throw std::invalid_argument("Spawn interval should be positive!");
		return;
	}
	this->spawnInterval = spawnInterval;
}
