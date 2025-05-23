#include "states/StartState.h"

#include "InputHandlers.h"
#include "states/PlayState.h"

const std::string FONT_PATH("src/fonts/Comic_Sans_MS.ttf");

StartState::StartState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize) : 
	window(window), inputManager(inputManager), logicalSize(logicalSize), pressedPlay(false), 
	playButton(std::make_shared<PlayButton>(sf::Vector2f(logicalSize.x / 2, logicalSize.y / 2), sf::Vector2f(0.3f * logicalSize.x, 0.15f * logicalSize.y), pressedPlay))
{
	if (font.loadFromFile(FONT_PATH))
		title.setFont(font);
	else
		throw std::runtime_error("Title font could not be loaded!");

	title.setString("Tubing");
	sf::Vector2f position(0.46f * logicalSize.x , 0.2f * logicalSize.y);
	title.setPosition(position);
	title.setOrigin(title.getScale().x / 2, title.getScale().y / 2);
	title.setFillColor(sf::Color::Black);

	std::unique_ptr<MouseInputHandler> mouseInputHandler = std::make_unique<MouseInputHandler>();
	mouseInputHandler->addListener(playButton);
	this->inputManager.addHandler(std::move(mouseInputHandler));
}

void StartState::render()
{
	window.clear(sf::Color::White);
	playButton->draw(window);
	window.draw(title);
	window.display();
}

std::unique_ptr<GameState> StartState::getNewState()
{
	if (pressedPlay)
	{
		pressedPlay = false;
		return std::make_unique<PlayState>(window, inputManager, logicalSize);
	}
	return nullptr;
}
