#include "Rope.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>

const sf::Color ROPE_COLOR(74, 37, 15);
const float ROPE_WIDTH = 3.5f;

Rope::Rope(sf::Vector2f& boatAnchorPoint, sf::Vector2f& tubeAnchorPoint) : 
	boatAnchorPoint(boatAnchorPoint),
   	tubeAnchorPoint(tubeAnchorPoint), 
	ropeSegment(boatAnchorPoint, tubeAnchorPoint, ROPE_WIDTH, ROPE_COLOR)
{}

void Rope::draw(sf::RenderTarget& target) const
{
	this->ropeSegment.draw(target);
}

void Rope::update(float dt)
{
	this->ropeSegment.changePoint1(this->boatAnchorPoint);
	this->ropeSegment.changePoint2(this->tubeAnchorPoint);
}
