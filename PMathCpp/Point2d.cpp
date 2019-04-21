#include <sstream>
#include "Point2d.h"
#include "Vector2d.h"
#include "Point2i.h"
#include "Line2.h"
#include "Circle.h"

using namespace ahs;

ahs::Point2d::Point2d()
    : _x{ 0 }
    , _y{ 0 }
{
}

ahs::Point2d::Point2d(Pdouble x, Pdouble y)
    : _x{ x }
    , _y{ y }
{
}

ahs::Point2d::Point2d(const Point2i& conv)
    : _x{ static_cast<Pdouble>(conv.x()) }
    , _y{ static_cast<Pdouble>(conv.y()) }
{
}

Pdouble ahs::Point2d::x() const
{
    return _x;
}

Pdouble ahs::Point2d::y() const
{
    return _y;
}

void ahs::Point2d::x(Pdouble value)
{
    _x = value;
}

void ahs::Point2d::y(Pdouble value)
{
    _y = value;
}

Point2d ahs::Point2d::operator+() const
{
    return Point2d{ +x(),+y() };
}

Point2d ahs::Point2d::operator-() const
{
    return Point2d{ -x(),-y() };
}

Point2d& ahs::Point2d::operator+=(const Point2d& other)
{
    x(x() + other.x());
    y(y() + other.y());

    return *this;
}

Point2d & ahs::Point2d::operator-=(const Point2d & other)
{
    x(x() - other.x());
    y(y() - other.y());

    return *this;
}

Point2d & ahs::Point2d::operator+=(const Vector2d & v)
{
    x(x() + v[0]);
    y(y() + v[1]);

    return *this;
}

Point2d & ahs::Point2d::operator-=(const Vector2d & v)
{
    x(x() - v[0]);
    y(y() - v[1]);

    return *this;
}

Point2d & ahs::Point2d::operator*=(Pdouble s)
{
    x(x() * s);
    y(y() * s);

    return *this;
}

Point2d& ahs::Point2d::operator/=(Pdouble s)
{
    x(x() / s);
    y(y() / s);

    return *this;
}

Point2d ahs::operator+(const Point2d & lhs, const Point2d & rhs)
{
    return Point2d{ lhs.x() + rhs.x(), lhs.y() + rhs.y() };
}

Point2d ahs::operator-(const Point2d & lhs, const Point2d & rhs)
{
    return Point2d{ lhs.x() - rhs.x(), lhs.y() - rhs.y() };
}

Point2d ahs::operator+(const Point2d & p, const Vector2d & v)
{
    return Point2d{ p.x() + v[0], p.y() + v[1] };
}

Point2d ahs::operator-(const Point2d & p, const Vector2d & v)
{
    return Point2d{ p.x() - v[0], p.y() - v[1] };
}

Point2d ahs::operator*(const Point2d & p, Pdouble s)
{
    return Point2d{ p.x() * s, p.y() * s };
}

Point2d ahs::operator*(Pdouble s, const Point2d & p)
{
    return p * s;
}

Point2d ahs::operator/(const Point2d & p, Pdouble s)
{
    return p * (1.0 / s);
}

Vector2d ahs::Point2d::to_vector() const
{
    return Vector2d{ x(), y() };
}

Vector2d ahs::Point2d::to_vector(const Point2d & origin) const
{
    return Vector2d{ x() - origin.x(), y() - origin.y() };
}

Pdouble ahs::Point2d::distance(const Point2d & other) const
{
    return (to_vector(other)).length();
}

Pdouble ahs::Point2d::distance(const Line2& l) const
{
    return l.distance(*this);
}

Pdouble ahs::Point2d::distance(const Circle& s) const
{
    return s.distance(*this);
}

std::string ahs::Point2d::to_string() const
{
    std::ostringstream oss;
    oss << '(' << x() << ", " << y() << ')';

    return oss.str();
}

Point2d ahs::Point2d::zero()
{
    return Point2d{ 0, 0 };
}
