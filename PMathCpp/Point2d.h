#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include <string>
#include "PTypeDefinition.h"

namespace ahs
{
    class Vector2d;
    class Point2i;
    class Line2;
    class Circle;

    class Point2d
    {
    public:
        Point2d();
        Point2d(Pdouble x, Pdouble y);
        Point2d(const Point2i& conv);
        virtual ~Point2d() = default;

    public: // get
        virtual Pdouble x() const;
        virtual Pdouble y() const;

    public: // set
        virtual void x(Pdouble value);
        virtual void y(Pdouble value);

    public: // operator
        virtual Point2d operator+() const;
        virtual Point2d operator-() const;
        virtual Point2d& operator+=(const Point2d& other);
        virtual Point2d& operator-=(const Point2d& other);
        virtual Point2d& operator+=(const Vector2d& v);
        virtual Point2d& operator-=(const Vector2d& v);
        virtual Point2d& operator*=(Pdouble s);
        virtual Point2d& operator/=(Pdouble s);

    public: // friend
        friend Point2d operator+(const Point2d& lhs, const Point2d& rhs);
        friend Point2d operator-(const Point2d& lhs, const Point2d& rhs);
        friend Point2d operator+(const Point2d& p, const Vector2d& v);
        friend Point2d operator-(const Point2d& p, const Vector2d& v);
        friend Point2d operator*(const Point2d& p, Pdouble s);
        friend Point2d operator*(Pdouble s, const Point2d& p);
        friend Point2d operator/(const Point2d& p, Pdouble s);

    public:
        virtual Vector2d to_vector() const;
        virtual Vector2d to_vector(const Point2d& origin) const;
        /*
        두 점 사이의 거리를 반환합니다.
        */
        virtual Pdouble distance(const Point2d& other) const;
        /*
        직선과 한 점 사이의 거리를 반환합니다.
        */
        virtual Pdouble distance(const Line2& l) const;
        /*
        원과 점 사이의 거리를 반환합니다. 점이 원 내부에 있다면 음수를 반환합니다.
        */
        virtual Pdouble distance(const Circle& s) const;
        virtual std::string to_string() const;

    public: // static
        static Point2d zero();

    private: // member
        Pdouble _x;
        Pdouble _y;
    };
}
