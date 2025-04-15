#pragma once

#include "IInputHandler.h"
#include <memory>
#include <vector>

// this is the object that is responsible for dispatching the events
// to the handlers in order to resolve which subscribers need to be 
// notified.
//
// as explained in InputHandlers.h, this is done by Chain of 
// Responsibility.
// but actually, InputManager can be seen as a facade:
//
// 1. it has a list of subclasses (the handlers)
// 2. provides a single entry method (processEvent)
// 3. protects the code, in the sense that the actual game loop
// 	  should have no business knowing which handler handles which
// 	  input, so the code is clean

class InputManager
{
private:
	// where the handlers reside
	std::vector<std::unique_ptr<IInputHandler>> handlers;

public:
	// method for adding new handlers
	void addHandler(std::unique_ptr<IInputHandler> handler);

	void processEvent(const sf::Event& event);
};
