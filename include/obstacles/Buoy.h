#include "Obstacle.h"

// buoy translates to "baliza" in romanian
class Buoy : public Obstacle
{
public:
	// not using constructor by parameter
	// to allow default creation for templates
	// Buoy(float posX);
	Buoy();
	Buoy(const Buoy& other);
	void update(float deltaTime) override;
	void createShape(float posX) override;
	std::unique_ptr<Obstacle> clone() const override;
};
