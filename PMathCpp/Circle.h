#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include "PTypeDefinition.h"
#include "Point2d.h"

namespace ahs
{
    class Circle
    {
    public:
        Circle();
        Circle(const Point2d& center, Pdouble radius);
        virtual ~Circle() = default;

    public: // get
        virtual const Point2d& center() const;
        virtual Pdouble radius() const;

    public: // set
        virtual void center(const Point2d& value);
        virtual void radius(Pdouble value);

    public:
        /*
        ���� �� ������ �Ÿ��� ��ȯ�մϴ�. ���� �� ���ο� �ִٸ� ������ ��ȯ�մϴ�.
        */
        virtual Pdouble distance(const Point2d& p) const;

    private: // member
        Point2d _center;
        Pdouble _radius;
    };
}
