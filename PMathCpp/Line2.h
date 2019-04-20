#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include "PTypeDefinition.h"
#include "Vector2d.h"
#include "Point2d.h"

namespace ahs
{
    class Line2
    {
    public:
        Line2();
        Line2(const Vector2d& direction, const Point2d& p0);
        Line2(const Point2d& p0, const Point2d& p1);
        virtual ~Line2() = default;

    public: // get
        const Vector2d& direction() const;
        const Point2d& p0() const;

    public: // set
        void direction(const Vector2d& value);
        void p0(const Point2d& value);

    public:
        Pdouble distance(const Point2d& p) const;

    private: // member
        Vector2d _direction;
        Point2d _p0;
    };
}
