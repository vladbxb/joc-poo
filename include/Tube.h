#include "IDrawable.h"
#include "IUpdatable.h"
#include "InputHandlers.h"
#include <SFML/Graphics/CircleShape.hpp>


// the Tube (which is moved by the player)
// should be drawable, updatable and also a listener
// because we need to know the mouse coordinates at all times
class Tube : public IDrawable, public IUpdatable, public IMouseListener
{
private:
	// we're gonna use a SFML circle for now
	sf::CircleShape shape;
	// this is the coordinates to the anchor point
	sf::Vector2f boatAnchor;
	// the length between the boat and the tube
	float ropeLength;
	// the size of the tube (circle)
	// it's not const because i don't know if i'm gonna
	// change it yet
	float radius;
	// the current X coordinate of the mouse
	// (set by the observer)
	float mouseX;

public:
	//Tube();
	Tube(const sf::Vector2f& boatAnchor, const sf::Vector2f& logicalSize);

	// we won't use dt because the circle
	// should instantly snap to the mouse
	// no acceleration or anything like that
	
	// updatable interface method override
	void update(float dt) override;
	// drawable interface method override
	void draw(sf::RenderTarget& target) const override;

	// and now the mouse listener interface method overrides
	void onMouseMoved(int x, int y) override;
	// we should implement this when jumping over obstacles
	void onMousePressed(sf::Mouse::Button, int x, int y) override {}
	// but this is not needed i don't think
	void onMouseReleased(sf::Mouse::Button, int x, int y) override {}
	// needed for the rope!	
	sf::Vector2f getAttachmentPoint() const;
	void setAnchorPoint(const sf::Vector2f& point);
};
