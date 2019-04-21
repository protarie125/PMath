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

std::array<Pdouble, 3> ahs::Line2::make_abc() const
{
    auto vx{ direction()[0] };
    auto vy{ direction()[1] };

    auto a{ vy };
    auto b{ -vx };
    auto c{ -vy * p0().x() + vx * p0().y() };

    return std::array<Pdouble, 3>{a, b, c};
}

Pdouble ahs::Line2::distance(const Point2d& p) const
{
    auto abc{ make_abc() };
    auto a{ abc[0] };
    auto b{ abc[1] };
    auto c{ abc[2] };
    return std::abs(a * p.x() + b * p.y() + c) / std::sqrt(a * a + b * b);
}

bool ahs::Line2::is_parallel(const Line2 & other) const
{
    auto v1{ direction() };
    auto v2{ other.direction() };

    auto dot{ v1.dot(v2) }; // = cos(theta)
    return (dot == 1 || dot == -1);
}

std::unique_ptr<Point2d> ahs::Line2::intersection(const Line2 & other) const
{
    if (is_parallel(other))
    {
        return nullptr;
    }
    else
    {
        auto abc1{ make_abc() };
        auto a1{ abc1[0] };
        auto b1{ abc1[1] };
        auto c1{ -abc1[2] };

        auto abc2{ other.make_abc() };
        auto a2{ abc2[0] };
        auto b2{ abc2[1] };
        auto c2{ -abc2[2] };

        auto det{ a1 * b2 - b1 * a2 };
        auto x{ (c1 * b2 - b1 * c2) / det };
        auto y{ (a1 * c2 - c1 * a2) / det };

        return std::make_unique<Point2d>(x, y);
    }
}