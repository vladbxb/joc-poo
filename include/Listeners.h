#pragma once

// this is where the listeners go, the actual "subscribers"
// which inherit this interface, so they can receive the corresponding input

class MouseListener
{
public:
	// relevant for the tube
	virtual void onMouseMoved(int x, int y) = 0;
	// relevant for clicking buttons
	virtual void onMousePressed(sf::Mouse::Button button, int x, int y) = 0;
	virtual void onMouseReleased(sf::Mouse::Button button, int x, int y) = 0;
	virtual ~MouseListener() = default;
};
