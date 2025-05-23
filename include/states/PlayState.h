#pragma once

#include "interfaces/GameState.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "obstacles/ObstacleManager.h"
#include "CollisionManager.h"
#include "Player.h"

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize);

	void init() override;
	void update(float dt) override;
	void render() override;
	
	std::unique_ptr<GameState> getNewState() override;
private:
	sf::RenderWindow& window;
	InputManager& inputManager;
	const sf::Vector2f& logicalSize;
	sf::Color backgroundColor;
	std::shared_ptr<Player> player;
	ObstacleManager obstacleManager;
	CollisionManager collisionManager;

	bool gameOver;
};
