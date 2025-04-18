#include <SFML/System/Vector2.hpp>

// for trigonometry
#include <cmath>

// helper function for keeping a value between bounds
float clamp(float value, float leftLim, float rightLim)
{
	if (value < leftLim)
		return leftLim;
	else
		if (value > rightLim)
			return rightLim;
	return value;
}

sf::Vector2f calculateTubePos(float mouseX, sf::Vector2f boatAnchor, float ropeLength)
{
	// this is the distance from the anchor point to
	// where the mouse is
	float dx = mouseX - boatAnchor.x;
	// these are the movement bounds for the circle
	// in actual tubing the tube can never be as far as the boat,
	// so this is why it's here
	float leftLim = -ropeLength * 0.8f;
	float rightLim = ropeLength * 0.8f;
	// now force it between these bounds
	dx = clamp(dx, leftLim, rightLim);
	float ratio = dx / ropeLength;
	// we need to ensure that the number passed to arcsin
	// is between -1 and 1, because of the mathematical
	// definition (otherwise it's gonna return garbage)
	ratio = clamp(ratio, -1.f, 1.f);

	// this is A^ in my drawing :)
	float angle = std::asin(ratio);

	// these formulas are derived from the sketches
	// on my tablet (check those if needed)
	float x = boatAnchor.x + ropeLength * std::sin(angle);
	float y = boatAnchor.y + ropeLength * std::cos(angle);

	sf::Vector2f tubePos(x, y);
	return tubePos;
}
