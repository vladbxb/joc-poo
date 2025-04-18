#include "Game.h"
#include <string>

const unsigned int GAME_WIDTH = 1280;
const unsigned int GAME_HEIGHT = 720;
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

void Game::update(float dt)
{
	this->player.update(dt);
}

void Game::render()
{
	this->window.clear(this->backgroundColor);
	// technically, this is where all of the IDrawables should have their
	// draw methods called!
	this->player.draw(this->window);
	this->window.display();
}

Game::Game() : window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME), logicalSize(static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)), player(this->logicalSize), frameRate(FRAME_RATE)
{
	this->window.setFramerateLimit(this->frameRate);
	this->backgroundColor = BACKGROUND_COLOR;

	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();

	MouseInputHandler* mouseInputHandlerRawP = mouseInputHandler.get();

	// mouseInputHandler->addListener(&player.getTube());
	this->player.addMouseDetection(*mouseInputHandlerRawP);

	this->inputManager.addHandler(std::move(mouseInputHandler));
}

void Game::run()
{
	// calculating delta time here
	sf::Time time = this->clock.restart();
	float dt = time.asSeconds();
	// the actual game loop
	while (this->window.isOpen())
	{
		this->processEvents();
		this->update(dt);
		this->render();
	}
}
