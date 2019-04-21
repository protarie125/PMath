#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include "PTypeDefinition.h"
#include "Point2i.h"

namespace ahs
{
    class Rect2i
    {
    public:
        Rect2i();
        Rect2i(Pint left, Pint top, Pint width, Pint height);
        Rect2i(const Point2i& left_top, Pint width, Pint height);
        Rect2i(const Point2i& left_top, const Point2i& right_bottom);
        virtual ~Rect2i() = default;

    public: // get
        virtual Pint left() const;
        virtual Pint top() const;
        virtual Pint width() const;
        virtual Pint height() const;
        virtual Pint right() const;
        virtual Pint bottom() const;

        virtual const Point2i& left_top() const;
        virtual const Point2i& left_bottom() const;
        virtual const Point2i& right_bottom() const;
        virtual const Point2i& right_top() const;

    public: // set
        virtual void left(Pint value);
        virtual void top(Pint value);
        virtual void width(Pint value);
        virtual void height(Pint value);

    public:
        virtual bool is_containing(const Point2i& p) const;
        virtual bool is_containing(const Rect2i& other) const;

    private: // member
        Pint _left;
        Pint _top;
        Pint _width;
        Pint _height;
    };
}
