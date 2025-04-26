#include "Rope.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>
#include <cmath>

Rope::Rope(const sf::Vector2f start, const sf::Vector2f end) : start(start), end(end), ROPE_COLOR(74, 37, 15), ROPE_WIDTH(3.5f), PI(3.141592) {}

void Rope::draw(sf::RenderTarget& target) const
{
	// we can draw the edges of a polygon with
	// sf::Vertex which is nice
	// drawing a line though
	// sf::Vertex line[2] = { 
	// 					   sf::Vertex(this->start, this->ROPE_COLOR),
	// 					   sf::Vertex(this->end, this->ROPE_COLOR)
	// 					 };
	
	// nevermind, sf::Vertex just draws one pixel
	// let's use RectangleShape to make the line bolder
	
	// this gives us the difference between the two vectors
	sf::Vector2f difference = this->start - this->end;
	// and we calculate the length of the vector using pythagoras
	float ropeLength = std::sqrt(difference.x * difference.x + difference.y * difference.y);
	// now we calculate the angle using arctg, because we have
	// y axis (opposite) and x axis (adjacent) vectors
	// thing is, std::atan2 returns radians, so we need to convert
	// those to degrees
	float angleInRads = std::atan2(difference.y, difference.x);
	float angleInDegs = (angleInRads * 180) / this->PI;

	// we calculate the ropeLength on the fly,
	// i can't think of a better way of doing it without
	// coupling stuff for no reason
	sf::RectangleShape ropeShape(sf::Vector2f(ropeLength, this->ROPE_WIDTH));
	
	ropeShape.setOrigin(0.f, this->ROPE_WIDTH / 2);
	ropeShape.setPosition(this->end);
	ropeShape.setFillColor(this->ROPE_COLOR);
	ropeShape.setRotation(angleInDegs);
	target.draw(ropeShape);
}

void Rope::update(sf::Vector2f start, sf::Vector2f end)
{
	this->start = start;
	this->end = end;
}
