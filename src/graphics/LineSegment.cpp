#include "graphics/LineSegment.h"
#include "math/MathFormulas.h"

LineSegment::LineSegment() : point1(0, 0), point2(0, 0), segment({0, 0}) {}
LineSegment::LineSegment(sf::Vector2f point1, sf::Vector2f point2, float thickness = 1, sf::Color color = sf::Color::Black) : point1(point1), point2(point2), thickness(thickness), color(color)
{
	this->segment.setFillColor(color);
	this->constructSegment();
}

void LineSegment::constructSegment()
{
	float angleInDegs = this->getRotationAngle();
	float length = calculateDistance(point1, point2);
	this->segment.setOrigin(0.f, this->thickness / 2);
	this->segment.setPosition(this->point1);
	sf::Vector2f segmentSize(length, this->thickness);
	this->segment.setSize(segmentSize);
	this->segment.setRotation(angleInDegs);
}

float LineSegment::getRotationAngle() const
{
	sf::Vector2f difference = this->point2 - this->point1;
	float angleInRads = std::atan2(difference.y, difference.x);
	float angleInDegs = convertRadsToDegs(angleInRads);
	return angleInDegs;
}

void LineSegment::changePoint1(sf::Vector2f point)
{
	this->point1 = point;
	this->constructSegment();
}

void LineSegment::changePoint2(sf::Vector2f point)
{
	this->point2 = point;
	this->constructSegment();
}

void LineSegment::draw(sf::RenderTarget& target) const
{
	target.draw(this->segment);
}
