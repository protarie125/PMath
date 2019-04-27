#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include "PTypeDefinition.h"
#include "Point2d.h"

namespace ahs
{
    class Rect2d
    {
    public:
        Rect2d();
        Rect2d(Pdouble left, Pdouble top, Pdouble width, Pdouble height);
        Rect2d(const Point2d& left_top, Pdouble width, Pdouble height);
        Rect2d(const Point2d& left_top, const Point2d& right_bottom);
        virtual ~Rect2d() = default;

    public: // get
        virtual Pdouble left() const;
        virtual Pdouble top() const;
        virtual Pdouble width() const;
        virtual Pdouble height() const;
        virtual Pdouble right() const;
        virtual Pdouble bottom() const;

        virtual const Point2d& left_top() const;
        virtual const Point2d& left_bottom() const;
        virtual const Point2d& right_bottom() const;
        virtual const Point2d& right_top() const;

    public: // set
        virtual void left(Pdouble value);
        virtual void top(Pdouble value);
        virtual void width(Pdouble value);
        virtual void height(Pdouble value);

    public:
        virtual bool is_containing(const Point2d& p) const;
        virtual bool is_containing(const Rect2d& other) const;

    private: // member
        Pdouble _left;
        Pdouble _top;
        Pdouble _width;
        Pdouble _height;
    };
}
