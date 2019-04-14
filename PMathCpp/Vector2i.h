#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include <array>
#include "PTypeDefinition.h"

namespace ahs
{
    class Vector2i
    {
    public:
        Vector2i();
        Vector2i(Pint v0, Pint v1);
        virtual ~Vector2i() = default;

    public: // get
        virtual Pint operator[](size_t index) const;

    public: // set
        virtual Pint& operator[](size_t index);

    public: // operator
        virtual Vector2i operator+() const;
        virtual Vector2i operator-() const;
        virtual Vector2i& operator+=(const Vector2i& other);
        virtual Vector2i& operator-=(const Vector2i& other);
        virtual Vector2i& operator*=(Pint n);

    public: // friend
        friend Vector2i operator+(const Vector2i& lhs, const Vector2i& rhs);
        friend Vector2i operator-(const Vector2i& lhs, const Vector2i& rhs);
        friend Vector2i operator*(const Vector2i& v, Pint n);
        friend Vector2i operator*(Pint n, const Vector2i& v);

    public:
        virtual Pdouble length();
        virtual Pint dot(const Vector2i& other) const;
        virtual Pint cross(const Vector2i& other) const;

    public: // static
        static Vector2i zero();
        static Vector2i e0();
        static Vector2i e1();

    private: // member
        std::array<Pint, 2> _data;

    private:
        bool _is_length_calced{ false };
        Pdouble _length;
    };
}
