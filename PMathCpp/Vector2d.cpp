#include <cmath>
#include <sstream>
#include "Vector2d.h"
#include "Vector2i.h"

using namespace ahs;

ahs::Vector2d::Vector2d()
    : _data{ 0,0 }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

ahs::Vector2d::Vector2d(Pdouble v0, Pdouble v1)
    : _data{ v0,v1 }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

ahs::Vector2d::Vector2d(const Vector2i& conv)
    : _data{ static_cast<Pdouble>(conv[0]),static_cast<Pdouble>(conv[1]) }
    , _length{ 0 }
    , _is_length_calced{ false }
{
}

Pdouble ahs::Vector2d::operator[](size_t index) const
{
    if (!(0 <= index && index < 2))
    {
        throw std::out_of_range{ "0 <= index && index < 2" };
    }

    return _data.at(index);
}

Pdouble& ahs::Vector2d::operator[](size_t index)
{
    if (!(0 <= index && index < 2))
    {
        throw std::out_of_range{ "0 <= index && index < 2" };
    }

    _is_length_calced = false; // setter가 불릴때마다 길이를 새로 계산해야 함을 표시합니다.
    return _data.at(index);
}

Vector2d ahs::Vector2d::operator+() const
{
    return Vector2d(_data[0], _data[1]);
}

Vector2d ahs::Vector2d::operator-() const
{
    return Vector2d(-_data[0], -_data[1]);
}

Vector2d& ahs::Vector2d::operator+=(const Vector2d & other)
{
    _data[0] += other[0];
    _data[1] += other[1];

    return *this;
}

Vector2d& ahs::Vector2d::operator-=(const Vector2d & other)
{
    _data[0] -= other[0];
    _data[1] -= other[1];

    return *this;
}

Vector2d& ahs::Vector2d::operator*=(Pdouble s)
{
    _data[0] *= s;
    _data[1] *= s;

    return *this;
}

Vector2d& ahs::Vector2d::operator/=(Pdouble s)
{
    _data[0] /= s;
    _data[1] /= s;

    return *this;
}

Pdouble ahs::Vector2d::length() const
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

Pdouble ahs::Vector2d::dot(const Vector2d & other) const
{
    return _data[0] * other[0] + _data[1] * other[1];
}

Pdouble ahs::Vector2d::cross(const Vector2d & other) const
{
    return _data[0] * other[1] - _data[1] * other[0];
}

Vector2d ahs::Vector2d::rotate(Pdouble radian) const
{
    auto cos = std::cos(radian);
    auto sin = std::sin(radian);

    auto x = cos * _data[0] - sin * _data[1];
    auto y = sin * _data[0] + cos * _data[1];

    return Vector2d{ x,y };
}

Vector2d ahs::Vector2d::normalize() const
{
    auto ret = (*this) / length();
    ret._length = 1;
    ret._is_length_calced = true;
    return ret;
}

std::string ahs::Vector2d::to_string() const
{
    std::ostringstream oss;
    oss << '[' << _data[0] << ", " << _data[1] << ']';

    return oss.str();
}

Vector2d ahs::Vector2d::zero()
{
    return Vector2d{ 0,0 };
}

Vector2d ahs::Vector2d::e0()
{
    return Vector2d{ 1,0 };
}

Vector2d ahs::Vector2d::e1()
{
    return Vector2d{ 0,1 };
}

Vector2d ahs::operator+(const Vector2d & lhs, const Vector2d & rhs)
{
    return Vector2d{ lhs[0] + rhs[0], lhs[1] + rhs[1] };
}

Vector2d ahs::operator-(const Vector2d & lhs, const Vector2d & rhs)
{
    return Vector2d{ lhs[0] - rhs[0], lhs[1] - rhs[1] };
}

Vector2d ahs::operator*(const Vector2d & v, Pdouble s)
{
    return Vector2d{ v[0] * s, v[1] * s };
}

Vector2d ahs::operator*(Pdouble s, const Vector2d & v)
{
    return v * s;
}

Vector2d ahs::operator/(const Vector2d & v, Pdouble s)
{
    return v * (1.0 / s);
}
