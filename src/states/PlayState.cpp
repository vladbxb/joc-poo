#include "states/PlayState.h"
#include "obstacles/Rock.h"
#include "obstacles/Buoy.h"

#include <SFML/Graphics.hpp>
#include <vector>

const sf::Color BACKGROUND_COLOR(18, 152, 255);

PlayState::PlayState(sf::RenderWindow& window, InputManager& inputManager, sf::Vector2f& logicalSize) : window(window), inputManager(inputManager), logicalSize(logicalSize), player(logicalSize), obstacleManager(0.275f * logicalSize.x, 0.725f * logicalSize.x, logicalSize.y)
{
	this->backgroundColor = BACKGROUND_COLOR;
	
	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();
	MouseInputHandler* mouseInputHandlerRawP = mouseInputHandler.get();
	this->player.addMouseDetection(*mouseInputHandlerRawP);
	this->inputManager.addHandler(std::move(mouseInputHandler));
}

void PlayState::init()
{
	// LEVEL 1 OBSTACLES
	std::vector<std::unique_ptr<Obstacle>> obstacles;
	obstacles.push_back(std::make_unique<Rock>());
	obstacles.push_back(std::make_unique<Buoy>());
	this->obstacleManager.setObstacleTemplate(obstacles);
	// LEVEL 1 SPAWNING INTERVAL
	this->obstacleManager.setSpawnInterval(0.8f);
	// turn it on
	this->obstacleManager.toggle();
}

void PlayState::update(float dt)
{
	this->obstacleManager.update(dt);
	this->player.update(dt);
	this->collisionManager.checkPlayerCollidesObstacles(this->player, this->obstacleManager.getActiveObstacles());
}

void PlayState::render()
{
	this->window.clear(this->backgroundColor);
	this->player.drawAllTrails(this->window);
	this->obstacleManager.draw(this->window);
	this->player.draw(this->window);
	this->window.display();
}
