#include "Game.h"
#include <string>

const unsigned int WINDOW_WIDTH = 1280;
const unsigned int WINDOW_HEIGHT = 720;
const unsigned int FRAME_RATE = 60;
const sf::Color BACKGROUND_COLOR(18, 152, 255);
const std::string GAME_NAME = "Joc POO";

void Game::processEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window.close();
		// no longer need these since we have InputManager :)
		//
		// if (event.type == sf::Event::MouseMoved)
		// {
		// 	this->mouseCoords.x = event.mouseMove.x;
		// 	this->mouseCoords.y = event.mouseMove.y;
		// }
		// if (event.type == sf::Event::Resized)
		// {
		// 	this->windowDim.x = event.size.width;
		// 	this->windowDim.y = event.size.height;
		// }
		this->inputManager.processEvent(event);
	}
}

void Game::update()
{
	// i don't know what i'm gonna use this for yet, honestly
	// this->player.update();
}

void Game::render()
{
	this->window.clear(this->backgroundColor);
	// technically, this is where all of the IDrawables should have their
	// draw methods called!
	// this->player.draw();
	this->window.display();
}

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME), frameRate(FRAME_RATE)
{
	this->windowDim.x = WINDOW_WIDTH;
	this->windowDim.y = WINDOW_HEIGHT;
	this->window.setFramerateLimit(this->frameRate);
	this->backgroundColor = BACKGROUND_COLOR;
}

void Game::run()
{
	// the actual game loop
	while (this->window.isOpen())
	{
		this->processEvents();
		this->update();
		this->render();
	}
}
