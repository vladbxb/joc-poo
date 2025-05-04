#pragma once

#include "obstacles/Obstacle.h"
#include "interfaces/Collidable.h"
#include "Player.h"

class CollisionManager
{
public:
	void checkPlayerCollidesObstacles(Player& player, const std::vector<std::unique_ptr<Obstacle>>& obstacles) const;
};
