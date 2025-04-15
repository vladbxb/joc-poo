// the Tube (which is moved by the player)
// should be drawable, updatable and also a listener
// because we need to know the mouse coordinates at all times
class Tube : public IDrawable, public IUpdatable, public IMouseListener
{
private:

