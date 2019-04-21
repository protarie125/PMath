#include "Circle.h"
#include "Vector2d.h"

using namespace ahs;

ahs::Circle::Circle()
    : _center{ Point2d::zero() }
    , _radius{ 0 }
{
}

ahs::Circle::Circle(const Point2d& center, Pdouble radius)
    : _center{ center }
    , _radius{ radius }
{
}

const Point2d& ahs::Circle::center() const
{
    return _center;
}

Pdouble ahs::Circle::radius() const
{
    return _radius;
}

void ahs::Circle::center(const Point2d& value)
{
    _center = value;
}

void ahs::Circle::radius(Pdouble value)
{
    _radius = value;
}

Pdouble ahs::Circle::distance(const Point2d& p) const
{
    auto d{ p.to_vector(center()).length() };
    return d - radius();
}
