#include <SFML/System/Vector2.hpp>

float clamp(float value, float leftLim, float rightLim);

sf::Vector2f getTubeBounds(float ropeLength);

float getXDiff(float mouseX, float boatAnchorX);
float getAngle();

float getXPos();
float getYPos();
float getYPosAirborne();

sf::Vector2f calculateTubePos(float mouseX, sf::Vector2f boatAnchor, float ropeLength);
sf::Vector2f calculateTubePosAirborne(float mouseX, sf::Vector2f boatAnchor, float ropeLength);
