#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	sf::Vector2i windowDim;
	sf::Vector2f mouseCoords;
	sf::Color backgroundColor;
	Player player;
	const int frameRate;
	void processEvents();
	void resize(int width, int height);
	void clear();
	void update();
	void draw();

	friend class Player;
public:
	Game();
	void run();
};
