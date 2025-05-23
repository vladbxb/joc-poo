#include "CollisionManager.h"

void CollisionManager::checkPlayerCollidesObstacles(std::shared_ptr<Player> player, const std::vector<std::unique_ptr<Obstacle>>& obstacles) const
{
	// iterate through each obstacle
	std::vector<std::unique_ptr<Obstacle>>::const_iterator oit;
	for (oit = obstacles.begin(); oit != obstacles.end(); ++oit)
	{
		// this is sf::Rect syntax
		if (player->getBounds().intersects((*oit)->getBounds()))
		{
			player->onCollision(**oit);
			(*oit)->onCollision(*player);
		}
	}
}
