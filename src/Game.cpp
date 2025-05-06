#include "Game.h"
#include <string>


// remove these dependencies later
#include "obstacles/Rock.h"
#include "obstacles/Buoy.h"

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
		this->inputManager.processEvent(event);
	}
}

void Game::update(float dt)
{
	this->obstacleManager.update(dt);
	this->player.update(dt);
	this->collisionManager.checkPlayerCollidesObstacles(this->player, this->obstacleManager.getActiveObstacles());
}

void Game::render()
{
	this->window.clear(this->backgroundColor);
	this->player.drawAllTrails(this->window);
	this->obstacleManager.draw(this->window);
	this->player.draw(this->window);
	this->window.display();
}

Game::Game() : 
	window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME),
   	logicalSize(static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)),
   	player(this->logicalSize),
   	frameRate(FRAME_RATE),
	obstacleManager(0.275f * GAME_WIDTH, 0.725f * GAME_WIDTH, GAME_HEIGHT)
{
	this->window.setFramerateLimit(this->frameRate);
	this->backgroundColor = BACKGROUND_COLOR;

	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();

	MouseInputHandler* mouseInputHandlerRawP = mouseInputHandler.get();

	this->player.addMouseDetection(*mouseInputHandlerRawP);

	this->inputManager.addHandler(std::move(mouseInputHandler));
}

void Game::run()
{




	// TODO: state management
	// these are placeholders CHANGE THESE LATER
	// LEVEL 1 OBSTACLES
	std::vector<std::unique_ptr<Obstacle>> obstacles;
	obstacles.push_back(std::make_unique<Rock>());
	obstacles.push_back(std::make_unique<Buoy>());
	this->obstacleManager.setObstacleTemplate(obstacles);
	// LEVEL 1 SPAWNING INTERVAL
	this->obstacleManager.setSpawnInterval(0.8f);
	// turn it on
	this->obstacleManager.toggle();




	// the actual game loop
	while (this->window.isOpen())
	{
		// calculating delta time here
		sf::Time time = this->clock.restart();
		float dt = time.asSeconds();
		this->processEvents();
		this->update(dt);
		this->render();
	}
}
