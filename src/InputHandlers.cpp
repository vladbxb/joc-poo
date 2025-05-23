#include "InputHandlers.h"

#include <iostream>

void MouseInputHandler::addListener(std::shared_ptr<MouseListener> listener)
{
    listeners.emplace_back(listener);
}

bool MouseInputHandler::handleEvent(const sf::Event& event)
{
	std::vector<std::weak_ptr<MouseListener>>::iterator cit = listeners.begin();
	while (cit != listeners.end())
	{
		// if reference count is zero
		if (cit->expired())
		{
			// erase listener from vector
			cit = listeners.erase(cit);
		}
		else
		{
			++cit;
		}
	}

    switch (event.type)
    {
    case sf::Event::MouseMoved:
    {
        std::vector<std::weak_ptr<MouseListener>>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
		{
			// make sure listener shared pointer has not expired
			std::shared_ptr<MouseListener> currentListener = it->lock();
			if (currentListener)
			{
            	currentListener->onMouseMoved(event.mouseMove.x, event.mouseMove.y);
			}
		}
        return true;
    }
    case sf::Event::MouseButtonPressed:
    {
        std::vector<std::weak_ptr<MouseListener>>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
		{
			std::shared_ptr<MouseListener> currentListener = it->lock();
			if (currentListener)
			{
            	currentListener->onMousePressed(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			}
		}
        return true;
    }
    case sf::Event::MouseButtonReleased:
    {
        std::vector<std::weak_ptr<MouseListener>>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
		{
			std::shared_ptr<MouseListener> currentListener = it->lock();
			if (currentListener)
			{
            	currentListener->onMouseReleased(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			}
		}
        return true;
    }
    default:
        return false;
    }
    return false;
}
