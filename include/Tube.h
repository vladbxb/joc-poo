#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include "interfaces/Collidable.h"
#include "InputHandlers.h"
#include "TubeTrail.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <deque>

class Tube : public Drawable, public Updatable, public Collidable, public MouseListener
{
private:
	sf::CircleShape shape;
	sf::CircleShape shadow;
	sf::Vector2f position;
	float radius;
	sf::Vector2f origin;
	sf::Color color;
	float ropeLength;
	sf::Vector2f tubeAnchorPosition;
	sf::Vector2f& boatAnchorPosition;
	float gameHeight;
	float mouseX;
	std::deque<TubeTrail> trails;
	float timeSinceLastTrail;
	float trailSpawnInterval;

	std::shared_ptr<int> lives;
	std::shared_ptr<int> score;
	bool airborne;
	bool invulnerable;
	float timeSinceAirborne;
	float timeAllowedInAir;
	float timeSinceInvulnerable;
	float timeAllowedInvulnerable;
	void loseLife();
	void becomeInvulnerable();
	void showInvulnerability();
	void hideInvulnerability();
	void becomeVulnerable();

	bool isInvulnerable() const;

	void trackInvulnerability(float dt);
	void resetTimeInvulnerable();

	void jump();
	void land();
	void showShadow();
	void hideShadow();
	void drawShadow(sf::RenderTarget& target) const;
	void trackAirTime(float dt);
	void resetAirTime();

	void resetTrailTimeElapsed();

	void init();
	void initRadius();
	void initOrigin();
	void initColor();
	void initPos();
public:
	Tube(sf::Vector2f position, float radius, sf::Vector2f origin, sf::Color color, float ropeLength, sf::Vector2f tubeAnchorPosition, sf::Vector2f& boatAnchorPosition, float gameHeight, std::shared_ptr<int> lives, std::shared_ptr<int> score);


	void handleTrailSpawn(float deltaTime);
	void spawnTrail(float deSpawnHeight);
	void clearInactiveTrails();
	void updateAllTrails(float deltaTime);

	bool isAirborne() const;

	void incrementScoreByTime();
	void incrementScoreByJump();

	void update(float dt) override;
	void updateOnWater(float dt);
	void updateInAir(float dt);

	void draw(sf::RenderTarget& target) const override;
	void drawAllTrails(sf::RenderTarget& target) const;

	void onMouseMoved(int x, int y) override;
	void onMousePressed(sf::Mouse::Button, int x, int y) override;
	void onMouseReleased(sf::Mouse::Button, int x, int y) override {}
	sf::FloatRect getBounds() const override;
	void onCollision(Collidable& other) override;

	sf::Vector2f& getAnchor();
};
