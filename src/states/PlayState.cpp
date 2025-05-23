#include "states/PlayState.h"
#include "obstacles/Rock.h"
#include "obstacles/Buoy.h"
#include "states/EndState.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const sf::Color BACKGROUND_COLOR(18, 152, 255);

PlayState::PlayState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize) :
   	window(window), 
	inputManager(inputManager), 
	logicalSize(logicalSize), 
	player(std::make_shared<Player>(logicalSize)), 
	obstacleManager(0.275f * logicalSize.x, 0.725f * logicalSize.x, logicalSize.y), 
	gameOver(false)
{
	this->backgroundColor = BACKGROUND_COLOR;
	
	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();
	mouseInputHandler->addListener(player);
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
	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();
	mouseInputHandler->addListener(player);
	this->inputManager.addHandler(std::move(mouseInputHandler));
	this->obstacleManager.update(dt);
	this->player->update(dt);
	this->collisionManager.checkPlayerCollidesObstacles(this->player, this->obstacleManager.getActiveObstacles());
	if (*player->getPlayerLives() <= 0)
	{
		gameOver = true;
	}
}

void PlayState::render()
{
	this->window.clear(this->backgroundColor);
	this->player->drawAllTrails(this->window);
	this->obstacleManager.draw(this->window);
	this->player->draw(this->window);
	this->window.display();
}

std::unique_ptr<GameState> PlayState::getNewState()
{
	if (gameOver)
		return std::make_unique<EndState>(window, inputManager, logicalSize);
	return nullptr;
}
