#include "Obstacle.h"

class Rock : public Obstacle
{
private:
	void initShape();
	void initRadius();
	void initColor();
	void initOrigin();	
	void initPosition();
public:
	// see reason for comment in the Buoy.h file
	// Rock(float posX);
	// Rock();
	// copy constructor for the clone method
	// Rock(float bottomBound, float spawnPosX);
	Rock();
	Rock(const Rock& other);
	void update(float deltaTime) override;
	void createShape(float bottomBound, float spawnPosX) override;
	std::unique_ptr<Obstacle> clone() const override;
};
