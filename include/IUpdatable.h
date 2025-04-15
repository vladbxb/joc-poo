#pragma once

class IUpdatable
{
public:
	// abstract method (needs to be overridden
	virtual void update(float deltaTime) = 0;
	// default virtual destructor, might change later
	virtual ~IUpdatable() = default;
};
