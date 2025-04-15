#include "InputHandlers.h"

void MouseInputHandler::addListener(IMouseListener* listener)
{
    listeners.push_back(listener);
}

void MouseInputHandler::removeListener(IMouseListener* listener)
{
    std::vector<IMouseListener*>::iterator it;
    // unfortunately std::vector does not have a find method,
    // but since i'm more comfortable with it, i prefer
    // using a classic for loop with the iterator to remove the
    // listener
    for (it = this->listeners.begin(); it != this->listeners.end(); ++it)
    {
        // here we dereference the iterator, not the pointer,
        // so we still get a IMouseListener*
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
    // now when the corresponding event gets catched, we
    // dispatch it to every listener assigned to the 
    // input handler
    case sf::Event::MouseMoved:
    {
        std::vector<IMouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            // by dereferencing the iterator (getting the actual
            // pointer to the listener)
            (*it)->onMouseMoved(event.mouseMove.x, event.mouseMove.y);
        return true;
    }
    case sf::Event::MouseButtonPressed:
    {
        std::vector<IMouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            (*it)->onMousePressed(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
        return true;
    }
    case sf::Event::MouseButtonReleased:
    {
        std::vector<IMouseListener*>::iterator it;
        for (it = listeners.begin(); it != listeners.end(); ++it)
            (*it)->onMouseReleased(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
        return true;
    }
    default:
        return false;
    }
    return false;
}