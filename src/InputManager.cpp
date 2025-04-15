#include "InputManager.h"
#include "IInputHandler.h"

#include <SFML/Window/Event.hpp>
#include <vector>

void InputManager::addHandler(std::unique_ptr<IInputHandler> handler)
{
    // we use std::move to transfer the ownership to the vector
    // (since it's a unique_ptr, we have to do this)
    this->handlers.push_back(std::move(handler));
}

void InputManager::processEvent(const sf::Event& event)
{
    std::vector<std::unique_ptr<IInputHandler>>::iterator it;
    // we iterate through the handlers (Chain of Responsibility)
    // in order to find the handler responsible for the event
    // (if it exists)
    // once it's found, the chain breaks, and the subscribers
    // have been notified of the event!
    for (it = this->handlers.begin(); it != this->handlers.end(); ++it)
        if ((*it)->handleEvent(event))
            break;
}