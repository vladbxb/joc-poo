#include "states/EndState.h"

#include "InputHandlers.h"
#include "buttons/RestartButton.h"
#include "states/StartState.h"

#include <iostream>

const std::string FONT_PATH("src/fonts/Comic_Sans_MS.ttf");

EndState::EndState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize) :
	window(window), inputManager(inputManager), logicalSize(logicalSize), pressedRestart(false),
	restartButton(std::make_shared<RestartButton>(sf::Vector2f(logicalSize.x / 2, logicalSize.y / 2), sf::Vector2f(0.3f * logicalSize.x, 0.15f * logicalSize.y), pressedRestart))
{
	if (font.loadFromFile(FONT_PATH))
		title.setFont(font);
	else
		throw std::runtime_error("Title font could not be loaded!");

	title.setString("Game over!");
	sf::Vector2f position(0.46f * logicalSize.x , 0.2f * logicalSize.y);
	title.setPosition(position);
	title.setOrigin(title.getScale().x / 2, title.getScale().y / 2);
	title.setFillColor(sf::Color::Black);

	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();
	mouseInputHandler->addListener(restartButton);
	this->inputManager.addHandler(std::move(mouseInputHandler));
}

void EndState::render()
{
	window.clear(sf::Color::White);
	window.draw(title);
	window.display();
}

std::unique_ptr<GameState> EndState::getNewState()
{
	if (pressedRestart)
	{
		pressedRestart = false;
		return std::make_unique<StartState>(window, inputManager, logicalSize);
	}
	return nullptr;
}
