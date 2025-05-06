#pragma once

#include "hud/Score.h"
#include "hud/Lives.h"

class HUD : Drawable, Updatable
{
private:
	sf::Vector2f logicalSize;
	Score score;
	Lives lives;
public:
	HUD(sf::Vector2f logicalSize, std::shared_ptr<int> lives, std::shared_ptr<int> score);

	void incrementScoreByTime();
	// void incrementScoreByJump();

	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
};
