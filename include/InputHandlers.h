#pragma once

#include "IInputHandler.h"
#include "Listeners.h"
#include <SFML/Window/Event.hpp>
#include <vector>

// this is going to actually dispatch the events to the listeners
// (the objects that need mouse input)
class MouseInputHandler : public IInputHandler
{
private:
	// we use normal pointers here because the inheriting class doesn't actually own the listeners
	// so, raw pointers (the usual for observers) is applied here
	std::vector<IMouseListener*> listeners;
public:
	// the subscribe method
	void addListener(IMouseListener* listener);

	// the unsubscribe method
	void removeListener(IMouseListener* listener);

	// here we override the method from the abstract
	// class (interface) IInputHandler
	//
	// and we actually apply the Chain of Responsibility principle,
	// by testing every event until hitting the right one
	bool handleEvent(const sf::Event& event) override;
};
