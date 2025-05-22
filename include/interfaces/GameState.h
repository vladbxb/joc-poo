#pragma once

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

	virtual ~GameState() = default;
protected:
	bool started = 0;
};
