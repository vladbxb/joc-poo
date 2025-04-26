#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	// see reason for comment in the Buoy.h file
	// Rock(float posX);
	// Rock();
	// copy constructor for the clone method
	Rock();
	Rock(const Rock& other);
	void update(float deltaTime) override;
	void createShape(float posX) override;
	std::unique_ptr<Obstacle> clone() const override;
};
