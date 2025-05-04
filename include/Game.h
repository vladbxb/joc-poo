#pragma once

#include "InputManager.h"
#include "obstacles/ObstacleManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	InputManager inputManager;
	ObstacleManager obstacleManager;
	CollisionManager collisionManager;
	sf::Vector2i windowDim;
	sf::Vector2f logicalSize;
	sf::Color backgroundColor;
	sf::Clock clock;
	Player player;
	const int frameRate;
	void processEvents();
	void resize(int width, int height);
	void update(float dt);
	void render();

public:
	Game();
	void run();
};
