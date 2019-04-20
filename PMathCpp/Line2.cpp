#include <cmath>
#include "Line2.h"

using namespace ahs;

ahs::Line2::Line2()
    : _direction{ Vector2d::e0() }
    , _p0{ Point2d::zero() }
{
}

ahs::Line2::Line2(const Vector2d& direction, const Point2d& p0)
    : _p0{ p0 }
{
    this->direction(direction);
}

ahs::Line2::Line2(const Point2d& p0, const Point2d& p1)
    : _p0{ p0 }
{
    this->direction(p1.to_vector(p0));
}

const Vector2d& ahs::Line2::direction() const
{
    return _direction;
}

const Point2d& ahs::Line2::p0() const
{
    return _p0;
}

void ahs::Line2::direction(const Vector2d& value)
{
    if (value.length() == 0)
    {
        _direction = Vector2d::e0();
    }
    else if (value.length() == 1)
    {
        _direction = value;
    }
    else
    {
        _direction = value.normalize();
    }
}

void ahs::Line2::p0(const Point2d& value)
{
    _p0 = value;
}

Pdouble ahs::Line2::distance(const Point2d& p) const
{
    auto vx = direction()[0];
    auto vy = direction()[1];

    auto a = vy;
    auto b = -vx;
    auto c = -vy * p.x() + vx * p.y();
    return std::abs(c) / std::sqrt(a * a + b * b);
}
