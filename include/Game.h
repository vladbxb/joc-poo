#pragma once

#include "InputManager.h"
#include "states/PlayState.h"
#include <SFML/Graphics.hpp>


class Game
{
private:
	sf::RenderWindow window;
	InputManager inputManager;
	sf::Vector2f logicalSize;
	std::unique_ptr<GameState> gameState;
	sf::Clock clock;
	const int frameRate;
	void processEvents();
public:
	Game();
	void run();
};
