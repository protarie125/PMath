#include <cmath>
#include <sstream>
#include <stdexcept>
#include "Vector2i.h"
#include "Vector2d.h"

using namespace ahs;

ahs::Vector2i::Vector2i()
    : _data{ 0,0 }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

ahs::Vector2i::Vector2i(Pint v0, Pint v1)
    : _data{ v0,v1 }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

ahs::Vector2i::Vector2i(const Vector2d& conv)
    : _data{ static_cast<Pint>(conv[0]), static_cast<Pint>(conv[1]) }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

Pint ahs::Vector2i::operator[](size_t index) const
{
    if (!(0 <= index && index < 2))
    {
        throw std::out_of_range{ "0 <= index && index < 2" };
    }

    return _data.at(index);
}

Pint& ahs::Vector2i::operator[](size_t index)
{
    if (!(0 <= index && index < 2))
    {
        throw std::out_of_range{ "0 <= index && index < 2" };
    }

    _is_length_calced = false; // setter가 불릴때마다 길이를 새로 계산해야 함을 표시합니다.
    return _data.at(index);
}

Vector2i ahs::Vector2i::operator+() const
{
    return Vector2i(_data[0], _data[1]);
}

Vector2i ahs::Vector2i::operator-() const
{
    return Vector2i(-_data[0], -_data[1]);
}

Vector2i& ahs::Vector2i::operator+=(const Vector2i & other)
{
    _data[0] += other[0];
    _data[1] += other[1];

    return *this;
}

Vector2i& ahs::Vector2i::operator-=(const Vector2i & other)
{
    _data[0] -= other[0];
    _data[1] -= other[1];

    return *this;
}

Vector2i& ahs::Vector2i::operator*=(Pint n)
{
    _data[0] *= n;
    _data[1] *= n;

    return *this;
}

Pdouble ahs::Vector2i::length() const
{
    if (!_is_length_calced)
    {
        auto v0 = _data[0];
        auto v1 = _data[1];
        _length = std::sqrt(v0 * v0 + v1 * v1);
        _is_length_calced = true;
    }
    return _length;
}

Pint ahs::Vector2i::dot(const Vector2i & other) const
{
    return _data[0] * other[0] + _data[1] * other[1];
}

Pint ahs::Vector2i::cross(const Vector2i & other) const
{
    return _data[0] * other[1] - _data[1] * other[0];
}

std::string ahs::Vector2i::to_string() const
{
    std::ostringstream oss;
    oss << '[' << _data[0] << ", " << _data[1] << ']';

    return oss.str();
}

Vector2i ahs::Vector2i::zero()
{
    return Vector2i{ 0,0 };
}

Vector2i ahs::Vector2i::e0()
{
    return Vector2i{ 1,0 };
}

Vector2i ahs::Vector2i::e1()
{
    return Vector2i{ 0,1 };
}

Vector2i ahs::operator+(const Vector2i & lhs, const Vector2i & rhs)
{
    return Vector2i{ lhs[0] + rhs[0], lhs[1] + rhs[1] };
}

Vector2i ahs::operator-(const Vector2i & lhs, const Vector2i & rhs)
{
    return Vector2i{ lhs[0] - rhs[0], lhs[1] - rhs[1] };
}

Vector2i ahs::operator*(const Vector2i & v, Pint n)
{
    return Vector2i{ v[0] * n, v[1] * n };
}

Vector2i ahs::operator*(Pint n, const Vector2i & v)
{
    return v * n;
}
