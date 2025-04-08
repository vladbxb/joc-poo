#include "Game.h"
#include "Player.h"
#include <string>

const unsigned int LUNGIME_FEREASTRA = 1280;
const unsigned int LATIME_FEREASTRA = 720;
const unsigned int FRAME_RATE = 60;
const sf::Color BACKGROUND_COLOR(18, 152, 255);
const std::string NUME_JOC = "Joc POO >:3";

void Game::processEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window.close();
		if (event.type == sf::Event::MouseMoved)
		{
			this->mouseCoords.x = event.mouseMove.x;
			this->mouseCoords.y = event.mouseMove.y;
		}
		if (event.type == sf::Event::Resized)
		{
			this->windowDim.x = event.size.width;
			this->windowDim.y = event.size.height;
		}
	}
}

void Game::clear()
{
	this->window.clear(this->backgroundColor);
}

void Game::update()
{
	this->player.update();
}

void Game::draw()
{
	this->clear();
	this->player.draw();
	this->window.display();
}

Game::Game() : window(sf::VideoMode(LUNGIME_FEREASTRA, LATIME_FEREASTRA), NUME_JOC), frameRate(FRAME_RATE), player(Player(*this))
{
	this->windowDim.x = LUNGIME_FEREASTRA;
	this->windowDim.y = LATIME_FEREASTRA;
	this->window.setFramerateLimit(this->frameRate);
	this->backgroundColor = BACKGROUND_COLOR;
}

void Game::run()
{
	while (this->window.isOpen())
	{
		this->processEvents();
		this->clear();
		this->update();
		this->draw();
	}
}
