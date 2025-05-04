#include "obstacles/ObstacleManager.h"

#include "obstacles/Obstacle.h"
#include <vector>
#include <memory>


// FOR DEBUGGING
#include <iostream>

ObstacleManager::ObstacleManager(float leftLim, float rightLim) : 
	spawner(this->obstacleTemplate, leftLim, rightLim), 
	active(false),
	gameWidth(rightLim - leftLim)
{}

void ObstacleManager::draw(sf::RenderTarget& target) const
{
	if (!this->active)
		return;

	// const iterator because draw is marked as const
	std::vector<std::unique_ptr<Obstacle>>::const_iterator oit;

	// call the draw method on each obstacle
	for (oit = this->activeObstacles.begin(); oit != this->activeObstacles.end(); ++oit)
		// oit is a pointer to a pointer, dereference it twice
		(*oit)->draw(target);
}

void ObstacleManager::update(float deltaTime)
{
	if (!this->active)
		return;
	
	// try to receive a spawned obstacle from the spawner
	std::unique_ptr<Obstacle> spawned = this->spawner.trySpawning(deltaTime);
	if (spawned)
	{
		// if it spawned (it's not nullptr) then store the pointer in 
		// active obstacles and give pointer ownership to the manager
		this->activeObstacles.push_back(std::move(spawned));
	}

	std::vector<std::unique_ptr<Obstacle>>::iterator oit;
	for (oit = this->activeObstacles.begin(); oit != this->activeObstacles.end(); ++oit)
		(*oit)->update(deltaTime);
}

void ObstacleManager::toggle()
{
	// negate the bool
	this->active = !this->active;
}

const std::vector<std::unique_ptr<Obstacle>>& ObstacleManager::getActiveObstacles() const
{
	return this->activeObstacles;
}

void ObstacleManager::setObstacleTemplate(const std::vector<std::unique_ptr<Obstacle>>& newTemplate)
{
	// clear the current template
	this->obstacleTemplate.clear();
	// iterate through new template
	std::vector<std::unique_ptr<Obstacle>>::const_iterator oit;
	for (oit = newTemplate.begin(); oit != newTemplate.end(); ++oit)
	{
		// add each obstacle in new template to the current manager's template
		this->obstacleTemplate.push_back((*oit)->clone());
	}
}

void ObstacleManager::setSpawnInterval(float spawnInterval)
{
	this->spawner.setSpawnInterval(spawnInterval);
}
