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

	// game bounds
	float leftLim;
	float rightLim;
	float bottomBound;

	std::mt19937 rng;

public:
	ObstacleSpawner(const std::vector<std::unique_ptr<Obstacle>>& obstacleTemplate, float leftLim, float rightLim, float bottomBound);

	std::unique_ptr<Obstacle> trySpawning(float deltaTime);
	std::unique_ptr<Obstacle> spawn();

	void testTemplateEmptiness() const;
	void resetElapsedTime();
	int getRandomIndex();
	int getRandomXValue(float leftLim, float rightLim);
	std::unique_ptr<Obstacle> cloneRandomObstacle();

	void setSpawnInterval(float spawnInterval);
};
