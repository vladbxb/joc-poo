#pragma once

#include <memory>

class GameState
{
public:
	virtual void run(float dt)
	{
		if (!started)
		{
			init();
			started = true;
		}
		update(dt);
		render();
	}
	virtual void init() {}
	virtual void update(float dt) = 0;
	virtual void render() = 0;

	// convention:
	// return new state if state needs changed
	// return nullptr if not
	virtual std::unique_ptr<GameState> getNewState() = 0;

	virtual ~GameState() = default;
protected:
	bool started = 0;
};
