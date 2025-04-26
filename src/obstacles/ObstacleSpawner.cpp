#include "obstacles/ObstacleSpawner.h"

#include <exception>
#include <random>

// REMOVE LATER (for debugging purposes)
#include <iostream>

// this is bad practice, needs to be changed later
const unsigned int GAME_WIDTH = 1280;
const unsigned int GAME_HEIGHT = 720;

const float LEFT_LIM_X = 0.15f * GAME_WIDTH;
const float RIGHT_LIM_X = 0.85f * GAME_WIDTH;

// WARNING: the spawn interval must be set manually with the setter
// only for now until i figure out scene / state management
ObstacleSpawner::ObstacleSpawner(const std::vector<std::unique_ptr<Obstacle>>& obstacleTemplate) : obstacleTemplate(obstacleTemplate), rng(std::random_device{}()), timeSinceLastSpawn(0.f), spawnInterval(0.f) {}

std::unique_ptr<Obstacle> ObstacleSpawner::trySpawning(float deltaTime)
{
	if (this->obstacleTemplate.empty())
		throw std::runtime_error("Obstacle template is empty!");

	// FOR DEBUGGING, delete later

	// std::cout << "timeSinceLastSpawn: " << this->timeSinceLastSpawn << '\n';
	// std::cout << "spawnInterval: " << this->spawnInterval << '\n';

	if (this->timeSinceLastSpawn < this->spawnInterval)
	{
		// if not enough time has elapsed, don't spawn
		// and increase the time
		this->timeSinceLastSpawn += deltaTime;
		return nullptr;
	}

	// the obstacle can be spawned
	// so we reset the elapsed time
	this->timeSinceLastSpawn = 0.f;
	// then we cast the template size to int (it's size_t by default)
	int templateSizeToInt = static_cast<int>(this->obstacleTemplate.size() - 1);
	// so it can be used by uniform_int_distribution
	std::uniform_int_distribution<int> distrib(0, templateSizeToInt);
	// generate the number
	int index = distrib(this->rng);
	// and clone the specific obstacle
	std::unique_ptr<Obstacle> spawned = this->obstacleTemplate[index]->clone();

	// generate a random X value for the obstacle to spawn
	std::uniform_int_distribution<int> posXDistrib(LEFT_LIM_X, RIGHT_LIM_X);
	int posX = posXDistrib(this->rng);

	// and set the concrete start position
	spawned->createShape(posX);
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
