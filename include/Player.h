#pragma once

#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include "interfaces/Collidable.h"
#include "Boat.h"
#include "Tube.h"
#include "Rope.h"
#include "InputHandlers.h"
#include "hud/HUD.h"

class Player : public Drawable, public Updatable, public Collidable
{
private:
	const sf::Vector2f& logicalSize;
	std::shared_ptr<int> lives;
	std::shared_ptr<int> score;
	float timeElapsedScore;
	float scoreGainInterval;
	Boat boat;
	Tube tube;
	Rope rope;
	HUD playerHUD;

	sf::Vector2f initBoatPosition() const;
	sf::Vector2f initBoatSize() const;
	sf::Vector2f initBoatOrigin() const;
	sf::Color initBoatColor() const;
	sf::Vector2f initBoatAnchorPosition() const;

	sf::Vector2f initTubePosition() const;
	float initTubeRadius() const;
	sf::Vector2f initTubeOrigin() const;
	sf::Color initTubeColor() const;
	float initRopeLength() const;
	sf::Vector2f initTubeAnchorPosition() const;

	void tryIncrementingScoreByTime(float dt);
	void incrementScoreByTime();
	void resetElapsedTime();
public:
	Player(const sf::Vector2f& logicalSize);

	void update(float dt) override;
	void draw(sf::RenderTarget& target) const override;
	void drawAllTrails(sf::RenderTarget& target) const;

	void addMouseDetection(MouseInputHandler& mip);

	sf::FloatRect getBounds() const override;
	void onCollision(Collidable& other) override;
};
