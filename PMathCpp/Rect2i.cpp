#include "Rect2i.h"

using namespace ahs;

ahs::Rect2i::Rect2i()
    : _left{ 0 }
    , _top{ 0 }
    , _width{ 0 }
    , _height{ 0 }
{
}

ahs::Rect2i::Rect2i(Pint left, Pint top, Pint width, Pint height)
    : _left{ left }
    , _top{ top }
{
    _width = (width < 1) ? 1 : width;
    _height = (height < 1) ? 1 : height;
}

ahs::Rect2i::Rect2i(const Point2i& left_top, Pint width, Pint height)
    : _left{ left_top.x() }
    , _top{ left_top.y() }
{
    _width = (width < 1) ? 1 : width;
    _height = (height < 1) ? 1 : height;
}

ahs::Rect2i::Rect2i(const Point2i& left_top, const Point2i& right_bottom)
    : _left{ left_top.x() }
    , _top{ left_top.y() }
{
    auto w_temp = right_bottom.x() - left_top.x() + 1;
    auto h_temp = right_bottom.y() - left_top.y() + 1;

    _width = (w_temp < 1) ? 1 : w_temp;
    _height = (h_temp < 1) ? 1 : h_temp;
}

Pint ahs::Rect2i::left() const
{
    return _left;
}

Pint ahs::Rect2i::top() const
{
    return _top;
}

Pint ahs::Rect2i::width() const
{
    return _width;
}

Pint ahs::Rect2i::height() const
{
    return _height;
}

Pint ahs::Rect2i::right() const
{
    return left() + width() - 1;
}

Pint ahs::Rect2i::bottom() const
{
    return top() + height() - 1;
}

const Point2i& ahs::Rect2i::left_top() const
{
    return Point2i{ left(), top() };
}

const Point2i& ahs::Rect2i::left_bottom() const
{
    return Point2i{ left(), bottom() };
}

const Point2i& ahs::Rect2i::right_bottom() const
{
    return Point2i{ right(), bottom() };
}

const Point2i& ahs::Rect2i::right_top() const
{
    return Point2i{ right(), top() };
}

void ahs::Rect2i::left(Pint value)
{
    _left = value;
}

void ahs::Rect2i::top(Pint value)
{
    _top = value;
}

void ahs::Rect2i::width(Pint value)
{
    _width = value;
}

void ahs::Rect2i::height(Pint value)
{
    _height = value;
}

bool ahs::Rect2i::is_containing(const Point2i& p) const
{
    return (left() <= p.x() && p.x() <= right() &&
        top() <= p.y() && p.y() <= bottom());
}

bool ahs::Rect2i::is_containing(const Rect2i& other) const
{
    return (left() <= other.left() &&
        other.right() <= right() &&
        top() <= other.top() &&
        other.bottom() <= bottom());
}
