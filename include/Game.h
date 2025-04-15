#pragma once

#include "InputManager.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	InputManager inputManager;
	sf::Vector2i windowDim;
	sf::Vector2f mouseCoords;
	sf::Color backgroundColor;
	// Player player;
	const int frameRate;
	void processEvents();
	void resize(int width, int height);
	void update();
	void render();

public:
	Game();
	void run();
};
