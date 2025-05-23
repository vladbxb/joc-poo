#pragma once

#include "interfaces/GameState.h"
#include "InputManager.h"
#include "buttons/PlayButton.h"

class StartState : public GameState
{
public:
	StartState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize);
	
	void update(float dt) override {}
	void render() override;

	std::unique_ptr<GameState> getNewState() override;
private:
	sf::RenderWindow& window;
	InputManager& inputManager;
	const sf::Vector2f& logicalSize;
	sf::Font font;
	sf::Text title;
	bool pressedPlay;
	std::shared_ptr<PlayButton> playButton;
};
