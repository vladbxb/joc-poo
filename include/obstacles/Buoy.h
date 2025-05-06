#include "Obstacle.h"

// buoy translates to "baliza" in romanian
class Buoy : public Obstacle
{
private:
	void initShape();
	void initColor();
	void initScale();
	void initOrigin();
	void initPosition();
public:
	// not using constructor by parameter
	// to allow default creation for templates
	// Buoy(float posX);
	// Buoy(float bottomBound, float spawnPosX);
	Buoy();
	Buoy(const Buoy& other);
	void update(float deltaTime) override;
	void createShape(float bottomBound, float spawnPosX) override;
	std::unique_ptr<Obstacle> clone() const override;
};
