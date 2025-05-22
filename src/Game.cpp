#include "Game.h"
#include <string>

const unsigned int GAME_WIDTH = 1280;
const unsigned int GAME_HEIGHT = 720;
const unsigned int FRAME_RATE = 60;
const std::string GAME_NAME = "Joc POO";

void Game::processEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window.close();
		this->inputManager.processEvent(event);
	}
}

Game::Game() : 
	window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME),
   	logicalSize(static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)),
	gameState(std::make_unique<PlayState>(this->window, this->inputManager, this->logicalSize)),
   	frameRate(FRAME_RATE)
{
	this->window.setFramerateLimit(this->frameRate);
}

void Game::run()
{
	// the actual game loop
	while (this->window.isOpen())
	{
		// calculating delta time here
		sf::Time time = this->clock.restart();
		float dt = time.asSeconds();
		this->processEvents();
		gameState->run(dt);
	}
}
