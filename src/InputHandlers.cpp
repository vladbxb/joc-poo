#include "InputHandlers.h"

void MouseInputHandler::addListener(MouseListener* listener)
{
    listeners.push_back(listener);
}

void MouseInputHandler::removeListener(MouseListener* listener)
{
    std::vector<MouseListener*>::iterator it;
    for (it = this->listeners.begin(); it != this->listeners.end(); ++it)
    {
        if (*it == listener)
        {
            listeners.erase(it);
            break;
        }
    }
}

bool MouseInputHandler::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseMoved:
    {
        std::vector<MouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            (*it)->onMouseMoved(event.mouseMove.x, event.mouseMove.y);
        return true;
    }
    case sf::Event::MouseButtonPressed:
    {
        std::vector<MouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            (*it)->onMousePressed(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
        return true;
    }
    case sf::Event::MouseButtonReleased:
    {
        std::vector<MouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            (*it)->onMouseReleased(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
        return true;
    }
    default:
        return false;
    }
    return false;
}
