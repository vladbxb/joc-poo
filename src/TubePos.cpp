#include "math/MathFormulas.h"
#include <SFML/System/Vector2.hpp>

// for trigonometry
#include <cmath>

sf::Vector2f getTubeBounds(float ropeLength)
{
	float leftLim = -ropeLength * 0.8f;
	float rightLim = ropeLength * 0.8f;
	return sf::Vector2f(leftLim, rightLim);
}

float getXDiff(float mouseX, float boatAnchorX)
{
	return mouseX - boatAnchorX;
}

float getAngle(float dx, float ropeLength)
{
	// ensure the tube can move only inside the x axis bounds
	dx = clamp(dx, getTubeBounds(ropeLength).x, getTubeBounds(ropeLength).y);
	// and that the ratio can be accepted by arcsin
	float ratio = clamp(dx / ropeLength, -1.f, 1.f);
	return std::asin(ratio);
}

float getXPos(float boatAnchorX, float ropeLength, float angle)
{
	return boatAnchorX + ropeLength * std::sin(angle);
}

float getYPos(float boatAnchorY, float ropeLength, float angle)
{
	return boatAnchorY + ropeLength * std::cos(angle);
}

float getYPosAirborne(float boatAnchorY, float ropeLength, float angle)
{
	return boatAnchorY + ropeLength * std::cos(angle) * 0.8f;
}


sf::Vector2f calculateTubePos(float mouseX, sf::Vector2f boatAnchor, float ropeLength)
{
	float dx = getXDiff(mouseX, boatAnchor.x);

	float angle = getAngle(dx, ropeLength);

	float x = getXPos(boatAnchor.x, ropeLength, angle);
	float y = getYPos(boatAnchor.y, ropeLength, angle);

	sf::Vector2f tubePos(x, y);
	return tubePos;
}

sf::Vector2f calculateTubePosAirborne(float mouseX, sf::Vector2f boatAnchor, float ropeLength)
{
	float dx = getXDiff(mouseX, boatAnchor.x);

	float angle = getAngle(dx, ropeLength);

	float x = getXPos(boatAnchor.x, ropeLength, angle);
	float y = getYPosAirborne(boatAnchor.y, ropeLength, angle);

	sf::Vector2f tubePos(x, y);
	return tubePos;
}
