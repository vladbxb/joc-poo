#pragma once

class TubeTrail : public Drawable, public Updatable
{
private:
	sf::CircleShape trailComponent;
	sf::Vector2f position;
	sf::Color color;
public:
	TubeTrail(sf::Vector2f startPosition, sf::Color color);

	void init();
	void initPosition();
	void initColor();

	void moveDown(float deltaTime);

	void draw(sf::RenderTarget& target) const override;
	void update(float deltaTime) override;
}
