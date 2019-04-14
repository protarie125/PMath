#include <sstream>
#include "Point2i.h"
#include "Vector2i.h"

using namespace ahs;

ahs::Point2i::Point2i()
    : _x{ 0 }
    , _y{ 0 }
{
}

ahs::Point2i::Point2i(Pint x, Pint y)
    : _x{ x }
    , _y{ y }
{
}

Pint ahs::Point2i::x() const
{
    return _x;
}

Pint ahs::Point2i::y() const
{
    return _y;
}

void ahs::Point2i::x(Pint value)
{
    _x = value;
}

void ahs::Point2i::y(Pint value)
{
    _y = value;
}

Point2i ahs::Point2i::operator+() const
{
    return Point2i{ x(),y() };
}

Point2i ahs::Point2i::operator-() const
{
    return Point2i{ -x(),-y() };
}

Point2i& ahs::Point2i::operator+=(const Point2i& other)
{
    x(x() + other.x());
    y(y() + other.y());

    return *this;
}

Point2i & ahs::Point2i::operator-=(const Point2i & other)
{
    x(x() - other.x());
    y(y() - other.y());

    return *this;
}

Point2i & ahs::Point2i::operator+=(const Vector2i & v)
{
    x(x() + v[0]);
    y(y() + v[1]);

    return *this;
}

Point2i & ahs::Point2i::operator-=(const Vector2i & v)
{
    x(x() - v[0]);
    y(y() - v[1]);

    return *this;
}

Point2i & ahs::Point2i::operator*=(Pint n)
{
    x(x() * n);
    y(y() * n);

    return *this;
}

Vector2i ahs::Point2i::to_vector() const
{
    return Vector2i{ x(), y() };
}

Vector2i ahs::Point2i::to_vector(const Point2i & origin) const
{
    return Vector2i{ x() - origin.x(), y() - origin.y() };
}

Pdouble ahs::Point2i::distance(const Point2i & other) const
{
    return (to_vector(other)).length();
}

std::string ahs::Point2i::to_string() const
{
    std::ostringstream oss;
    oss << '(' << x() << ", " << y() << ')';

    return oss.str();
}

Point2i ahs::Point2i::zero()
{
    return Point2i{ 0,0 };
}

Point2i ahs::operator+(const Point2i & lhs, const Point2i & rhs)
{
    return Point2i{ lhs.x() + rhs.x(),lhs.y() + rhs.y() };
}

Point2i ahs::operator-(const Point2i & lhs, const Point2i & rhs)
{
    return Point2i{ lhs.x() - rhs.x(),lhs.y() - rhs.y() };
}

Point2i ahs::operator+(const Point2i & p, const Vector2i & v)
{
    return Point2i{ v[0] + p.x(), v[1] + p.y() };
}

Point2i ahs::operator-(const Point2i & p, const Vector2i & v)
{
    return Point2i{ v[0] - p.x(), v[1] - p.y() };
}

Point2i ahs::operator*(const Point2i & p, Pint n)
{
    return Point2i{ p.x() * n, p.y() * n };
}

Point2i ahs::operator*(Pint n, const Point2i & p)
{
    return p * n;
}