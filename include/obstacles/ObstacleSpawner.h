#pragma once

#include "obstacles/Obstacle.h"
#include <random>
#include <memory>
#include <vector>

class ObstacleSpawner
{
private:
	const std::vector<std::unique_ptr<Obstacle>>& obstacleTemplate;
	float timeSinceLastSpawn;
	float spawnInterval;

	std::mt19937 rng;
public:
	ObstacleSpawner(const std::vector<std::unique_ptr<Obstacle>>& obstacleTemplate);

	std::unique_ptr<Obstacle> trySpawning(float deltaTime);
	void setSpawnInterval(float spawnInterval);
};
