#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include <string>
#include <array>
#include "PTypeDefinition.h"

namespace ahs
{
    class Vector2d
    {
    public:
        Vector2d();
        Vector2d(Pdouble v0, Pdouble v1);
        virtual ~Vector2d() = default;

    public: // get
        virtual Pdouble operator[](size_t index) const;

    public: // set
        virtual Pdouble& operator[](size_t index);

    public: // operator
        virtual Vector2d operator+() const;
        virtual Vector2d operator-() const;
        virtual Vector2d& operator+=(const Vector2d& other);
        virtual Vector2d& operator-=(const Vector2d& other);
        virtual Vector2d& operator*=(Pdouble s);
        virtual Vector2d& operator/=(Pdouble s);

    public: // friend
        friend Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs);
        friend Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs);
        friend Vector2d operator*(const Vector2d& v, Pdouble s);
        friend Vector2d operator*(Pdouble s, const Vector2d& v);
        friend Vector2d operator/(const Vector2d& v, Pdouble s);

    public:
        virtual Pdouble length();
        virtual Pdouble dot(const Vector2d& other) const;
        virtual Pdouble cross(const Vector2d& other) const;
        virtual Vector2d rotate(Pdouble radian) const;
        virtual Vector2d normalize();
        virtual std::string to_string() const;

    public: // static
        static Vector2d zero();
        static Vector2d e0();
        static Vector2d e1();

    private: // member
        std::array<Pdouble, 2> _data;

    private:
        bool _is_length_calced;
        Pdouble _length;
    };
}
