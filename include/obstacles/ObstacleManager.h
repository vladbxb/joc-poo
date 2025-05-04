#pragma once

#include "obstacles/Obstacle.h"
#include "obstacles/ObstacleSpawner.h"
#include <vector>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>

class ObstacleManager : public Drawable, public Updatable
{
private:
	std::vector<std::unique_ptr<Obstacle>> obstacleTemplate;
	std::vector<std::unique_ptr<Obstacle>> activeObstacles;
	ObstacleSpawner spawner;
	bool active;
	float gameWidth;
public:
	ObstacleManager(float leftLim, float rightLim);
	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
	// how it will be turned on or off
	void toggle();
	const std::vector<std::unique_ptr<Obstacle>>& getActiveObstacles() const;
	void setObstacleTemplate(const std::vector<std::unique_ptr<Obstacle>>& newTemplate);
	void setSpawnInterval(float spawnInterval);
};
