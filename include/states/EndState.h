#pragma once

#include "interfaces/GameState.h"
#include "InputManager.h"
#include "buttons/RestartButton.h"

class EndState : public GameState
{
public:
	EndState(sf::RenderWindow& window, InputManager& inputManager, const sf::Vector2f& logicalSize);
	
	void update(float dt) override {}
	void render() override;

	std::unique_ptr<GameState> getNewState() override;
private:
	sf::RenderWindow& window;
	InputManager& inputManager;
	const sf::Vector2f& logicalSize;
	sf::Font font;
	sf::Text title;
	bool pressedRestart;
	std::shared_ptr<RestartButton> restartButton;
};
