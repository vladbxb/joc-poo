#include "hud/HUD.h"

HUD::HUD(sf::Vector2f logicalSize, std::shared_ptr<int> lives, std::shared_ptr<int> score) :
	logicalSize(logicalSize),
	score(score, sf::Vector2f(logicalSize.x * 0.8f, logicalSize.y * 0.05f)),
	lives(lives, sf::Vector2f(logicalSize.x * 0.02f, logicalSize.y * 0.05f))
{}

void HUD::incrementScoreByTime()
{
	this->score.incrementScoreByTime();
}

// void HUD::incrementScoreByJump()
// {
// 	this->score.incrementScoreByJump();
// }

void HUD::draw(sf::RenderTarget& target) const
{
	this->score.draw(target);
	this->lives.draw(target);
}

void HUD::update(float deltaTime)
{
	this->score.update(deltaTime);
	this->lives.update(deltaTime);
}
