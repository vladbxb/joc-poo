#pragma once

#include <SFML/Window/Event.hpp>

class IInputHandler
{
public:
	virtual bool handleEvent(const sf::Event& event) = 0;
	virtual ~IInputHandler() = default;
};
