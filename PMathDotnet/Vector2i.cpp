#include "Vector2i.h"

namespace PMathDotnet
{
    Vector2i::Vector2i()
    {
        _native = new ahs::Vector2i{};
    }

    Vector2i::Vector2i(Int32 v0, Int32 v1)
    {
        _native = new ahs::Vector2i{ v0, v1 };
    }

    Vector2i::!Vector2i()
    {
        delete _native;
    }

    Vector2i^ Vector2i::operator+(Vector2i^ v)
    {
        ahs::Vector2i nat = +(*(v->_native));
        return gcnew Vector2i{ nat[0], nat[1] };
    }

    Vector2i^ Vector2i::operator-(Vector2i^ v)
    {
        ahs::Vector2i nat = +(*(v->_native));
        return gcnew Vector2i{ -nat[0], -nat[1] };
    }

    Vector2i^ Vector2i::operator+(Vector2i^ lhs, Vector2i^ rhs)
    {
        ahs::Vector2i nat = (*(lhs->_native)) + (*(rhs->_native));
        return gcnew Vector2i{ nat[0], nat[1] };
    }

    Vector2i^ Vector2i::operator-(Vector2i^ lhs, Vector2i^ rhs)
    {
        ahs::Vector2i nat = (*(lhs->_native)) - (*(rhs->_native));
        return gcnew Vector2i{ nat[0], nat[1] };
    }

    Vector2i^ Vector2i::operator*(Vector2i^ v, Int32 n)
    {
        ahs::Vector2i nat = (*(v->_native)) * n;
        return gcnew Vector2i{ nat[0], nat[1] };
    }

    Vector2i^ Vector2i::operator*(Int32 n, Vector2i^ v)
    {
        ahs::Vector2i nat = n * (*(v->_native));
        return gcnew Vector2i{ nat[0], nat[1] };
    }

    Int32 Vector2i::Dot(Vector2i^ other)
    {
        return _native->dot(*(other->_native));
    }

    Int32 Vector2i::Cross(Vector2i^ other)
    {
        return _native->cross(*(other->_native));
    }

    String^ Vector2i::ToString()
    {
        return gcnew String{ _native->to_string().c_str() };
    }
}
