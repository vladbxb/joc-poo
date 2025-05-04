#pragma once

#include <SFML/Window/Event.hpp>

class InputHandler
{
public:
	virtual bool handleEvent(const sf::Event& event) = 0;
	virtual ~InputHandler() = default;
};
