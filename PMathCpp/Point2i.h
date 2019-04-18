#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include "PTypeDefinition.h"

namespace ahs
{
    class Vector2i;
    class Point2d;

    class Point2i
    {
    public:
        Point2i();
        Point2i(Pint x, Pint y);
        explicit Point2i(const Point2d& conv);
        virtual ~Point2i() = default;

    public: // get
        virtual Pint x() const;
        virtual Pint y() const;

    public: // set
        virtual void x(Pint value);
        virtual void y(Pint value);

    public: // operator
        virtual Point2i operator+() const;
        virtual Point2i operator-() const;
        virtual Point2i& operator+=(const Point2i& other);
        virtual Point2i& operator-=(const Point2i& other);
        virtual Point2i& operator+=(const Vector2i& v);
        virtual Point2i& operator-=(const Vector2i& v);
        virtual Point2i& operator*=(Pint n);

    public: // friend
        friend Point2i operator+(const Point2i& lhs, const Point2i& rhs);
        friend Point2i operator-(const Point2i& lhs, const Point2i& rhs);
        friend Point2i operator+(const Point2i& p, const Vector2i& v);
        friend Point2i operator-(const Point2i& p, const Vector2i& v);
        friend Point2i operator*(const Point2i& p, Pint n);
        friend Point2i operator*(Pint n, const Point2i& p);

    public:
        virtual Vector2i to_vector() const;
        virtual Vector2i to_vector(const Point2i& origin) const;
        virtual Pdouble distance(const Point2i& other) const;
        virtual std::string to_string() const;

    public: // static
        static Point2i zero();

    private: // member
        Pint _x;
        Pint _y;
    };
}
