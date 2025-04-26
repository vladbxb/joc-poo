#pragma once

#include "obstacles/Obstacle.h"
#include "obstacles/ObstacleSpawner.h"
#include <vector>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>

class ObstacleManager : public IDrawable, public IUpdatable
{
private:
	std::vector<std::unique_ptr<Obstacle>> obstacleTemplate;
	std::vector<std::unique_ptr<Obstacle>> activeObstacles;
	ObstacleSpawner spawner;
	bool active;
public:
	ObstacleManager();
	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
	// how it will be turned on or off
	void toggle();
	void setObstacleTemplate(const std::vector<std::unique_ptr<Obstacle>>& newTemplate);
	void setSpawnInterval(float spawnInterval);
};
