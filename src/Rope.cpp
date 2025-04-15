#include "Rope.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

Rope::Rope(const sf::Vector2f& start, const sf::Vector2f& end) : start(start), end(end), ropeColor(74, 37, 15) {}

void Rope::draw(sf::RenderTarget& target) const
{
	// we can draw the edges of a polygon with
	// sf::Vertex which is nice
	// drawing a line though
	sf::Vertex line[2] = { 
						   sf::Vertex(start, this->ropeColor),
						   sf::Vertex(end, this->ropeColor)
						 };
	target.draw(line, 2, sf::Lines);

	// DELETE THIS AFTER
	std::cout << "Drawing rope from (" << start.x << ", " << start.y << ") to ("
          << end.x << ", " << end.y << ")\n";

}
