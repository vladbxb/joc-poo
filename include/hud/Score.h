#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Score : Drawable, Updatable
{
private:
	std::shared_ptr<int> score;
	sf::Vector2f position;
	sf::Text textEntity;
	std::string scoreString;
	sf::Font font;
	void updateScore();
	void setScoreString();
	void updateTextEntity();
	void initFont();
public:
	Score(std::shared_ptr<int> score, sf::Vector2f position);

	void incrementScoreByTime();
	// void incrementScoreByJump();

	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
};
