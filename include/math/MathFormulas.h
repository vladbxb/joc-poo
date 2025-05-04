#pragma once

#include <SFML/System/Vector2.hpp>

float calculateDistance(sf::Vector2f A, sf::Vector2f B);

float clamp(float value, float leftLim, float rightLim);

float convertRadsToDegs(float rads);
