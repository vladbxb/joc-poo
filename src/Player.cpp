#include "Player.h"

// this constructor is kinda ugly, i might
// change it later
Player::Player(const sf::Vector2f& logicalSize) : boat(logicalSize), tube(boat.getAnchorPoint(), logicalSize)
{
	//this->rope = Rope(boat.getAnchorPoint(), tube.getAttachmentPoint());
}

void Player::update(float dt)
{
	// here we just update the boat and the tube
	tube.setAnchorPoint(boat.getAnchorPoint());
	this->tube.update(dt);
}

void Player::draw(sf::RenderTarget& target) const
{
	// and here we draw it all
	this->boat.draw(target);
	// this->rope.draw(target);
	this->tube.draw(target);
}

Tube& Player::getTube()
{
	return this->tube;
}
