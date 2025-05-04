#include "interfaces/Drawable.h"
#include "interfaces/Updatable.h"
#include "interfaces/Collidable.h"
#include "InputHandlers.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

class Tube : public Drawable, public Updatable, public Collidable, public MouseListener
{
private:
	sf::CircleShape shape;
	sf::Vector2f position;
	float radius;
	sf::Vector2f origin;
	sf::Color color;
	float ropeLength;
	sf::Vector2f tubeAnchorPosition;
	sf::Vector2f& boatAnchorPosition;
	float mouseX;
	// std::vector<TubeTrail> trails;
public:
	Tube(sf::Vector2f position, float radius, sf::Vector2f origin, sf::Color color, float ropeLength, sf::Vector2f tubeAnchorPosition, sf::Vector2f& boatAnchorPosition);

	void init();
	void initRadius();
	void initOrigin();
	void initColor();
	void initPos();

	void update(float dt) override;
	void draw(sf::RenderTarget& target) const override;

	void onMouseMoved(int x, int y) override;
	void onMousePressed(sf::Mouse::Button, int x, int y) override {}
	void onMouseReleased(sf::Mouse::Button, int x, int y) override {}
	sf::FloatRect getBounds() const override;
	void onCollision(Collidable& other) override;

	sf::Vector2f& getAnchor();
};
