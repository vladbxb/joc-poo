#include "hud/Score.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <sstream>
#include <exception>

const std::string FONT_PATH("src/fonts/Comic_Sans_MS.ttf");

template <typename T>
std::string toString(const T& val)
{
	std::ostringstream ss;
	ss << val;
	return ss.str();
}

void Score::setScoreString()
{
	std::string scoreAsString = toString(*this->score);
	this->scoreString = "Score: ";
	this->scoreString.append(scoreAsString);
}

void Score::initFont()
{
	if (this->font.loadFromFile(FONT_PATH))
		this->textEntity.setFont(this->font);
	else
		throw std::runtime_error("Score font could not be loaded!");
}

void Score::updateTextEntity()
{
	this->textEntity.setString(this->scoreString);
	this->textEntity.setPosition(this->position);
}

void Score::updateScore()
{
	this->setScoreString();
	this->updateTextEntity();
}


Score::Score(std::shared_ptr<int> score, sf::Vector2f position) : score(score), position(position)
{
	this->setScoreString();
	this->initFont();
	this->updateTextEntity();
}

void Score::incrementScoreByTime()
{
	*this->score += 1;
}

// void Score::incrementScoreByJump()
// {
// 	this->score += 25;
// }

void Score::draw(sf::RenderTarget& target) const
{
	target.draw(this->textEntity);
}

void Score::update(float deltaTime)
{
	this->updateScore();
}
