#include "Rect2d.h"

using namespace ahs;

ahs::Rect2d::Rect2d()
    : _left{ 0 }
    , _top{ 0 }
    , _width{ 0 }
    , _height{ 0 }
{
}

ahs::Rect2d::Rect2d(Pdouble left, Pdouble top, Pdouble width, Pdouble height)
    : _left{ left }
    , _top{ top }
{
    _width = (width < 0) ? 0 : width;
    _height = (height < 0) ? 0 : height;
}

ahs::Rect2d::Rect2d(const Point2d& left_top, Pdouble width, Pdouble height)
    : _left{ left_top.x() }
    , _top{ left_top.y() }
{
    _width = (width < 0) ? 0 : width;
    _height = (height < 0) ? 0 : height;
}

ahs::Rect2d::Rect2d(const Point2d& left_top, const Point2d& right_bottom)
    : _left{ left_top.x() }
    , _top{ left_top.y() }
{
    auto w_temp = right_bottom.x() - left_top.x();
    auto h_temp = right_bottom.y() - left_top.y();

    _width = (w_temp < 0) ? 0 : w_temp;
    _height = (h_temp < 0) ? 0 : h_temp;
}

Pdouble ahs::Rect2d::left() const
{
    return _left;
}

Pdouble ahs::Rect2d::top() const
{
    return _top;
}

Pdouble ahs::Rect2d::width() const
{
    return _width;
}

Pdouble ahs::Rect2d::height() const
{
    return _height;
}

Pdouble ahs::Rect2d::right() const
{
    return left() + width();
}

Pdouble ahs::Rect2d::bottom() const
{
    return top() + height();
}

const Point2d& ahs::Rect2d::left_top() const
{
    return Point2d{ left(),top() };
}

const Point2d& ahs::Rect2d::left_bottom() const
{
    return Point2d{ left(),bottom() };
}

const Point2d& ahs::Rect2d::right_bottom() const
{
    return Point2d{ right(),bottom() };
}

const Point2d& ahs::Rect2d::right_top() const
{
    return Point2d{ right(),top() };
}

void ahs::Rect2d::left(Pdouble value)
{
    _left = value;
}

void ahs::Rect2d::top(Pdouble value)
{
    _top = value;
}

void ahs::Rect2d::width(Pdouble value)
{
    _width = (value < 0) ? 0 : value;
}

void ahs::Rect2d::height(Pdouble value)
{
    _height = (value < 0) ? 0 : value;
}

bool ahs::Rect2d::is_containing(const Point2d& p) const
{
    return (left() <= p.x() && p.x() <= right() &&
        top() <= p.y() && p.y() <= bottom());
}

bool ahs::Rect2d::is_containing(const Rect2d& other) const
{
    return (left() <= other.left() &&
        other.right() <= right() &&
        top() <= other.top() &&
        other.bottom() <= bottom());
}
