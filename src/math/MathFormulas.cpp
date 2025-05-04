#include "math/MathFormulas.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>

const float PI = 3.141592;

float clamp(float value, float leftLim, float rightLim)
{
	// keeps a value within bounds
	if (value < leftLim)
		return leftLim;
	else
		if (value > rightLim)
			return rightLim;
	return value;
}

float calculateDistance(sf::Vector2f A, sf::Vector2f B)
{
	// calculates the hypothenuse of a right triangle
	sf::Vector2f difference = A - B;
	return std::sqrt(difference.x * difference.x + difference.y * difference.y);
}

float convertRadsToDegs(float rads)
{
	return (rads * 180) / PI;
}
