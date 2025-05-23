#pragma once

#include "Listeners.h"
#include <SFML/Window/Mouse.hpp>

class Button : public MouseListener
{
public:
	void onMouseMoved(int x, int y) {}
	void onMousePressed(sf::Mouse::Button button, int x, int y) {}
	void onMouseReleased(sf::Mouse::Button button, int x, int y)
	{
		if (clickedInside(x, y))
		{
			command(button);
		}
	}
protected:
	virtual void command(sf::Mouse::Button button) = 0;
	virtual bool clickedInside(int x, int y) = 0;
};
