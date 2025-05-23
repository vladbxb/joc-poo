#pragma once

#include "interfaces/InputHandler.h"
#include "Listeners.h"
#include <SFML/Window/Event.hpp>
#include <vector>

// this is going to actually dispatch the events to the listeners
// (the objects that need mouse input)
class MouseInputHandler : public InputHandler
{
private:
	// inheriting class doesn't actually own the listeners
	// use raw pointers
	std::vector<std::weak_ptr<MouseListener>> listeners;
public:
	// the subscribe method
	void addListener(std::shared_ptr<MouseListener> listener);

	bool handleEvent(const sf::Event& event) override;
};
