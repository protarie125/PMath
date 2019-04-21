#pragma once
/*
 * E-mail: protarie@gmail.com
 * github: https://github.com/protarie125
 */
#include <array>
#include <memory>
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
        virtual const Vector2d& direction() const;
        virtual const Point2d& p0() const;

    public: // set
        virtual void direction(const Vector2d& value);
        virtual void p0(const Point2d& value);

    public:
        /*
        ������ 'ax + by + c = 0'������ �������� ���� ��� a, b, c�� ��ȯ�մϴ�.
        */
        virtual std::array<Pdouble, 3> make_abc() const;
        /*
        ������ �� �� ������ �Ÿ��� ��ȯ�մϴ�.
        */
        virtual Pdouble distance(const Point2d& p) const;
        /*
        �� ������ �������� �����մϴ�.
        */
        virtual bool is_parallel(const Line2& other) const;
        /*
        �� ������ ������ ��ȯ�մϴ�. ������ ���ٸ� nullptr�� ��ȯ�մϴ�.
        */
        virtual std::unique_ptr<Point2d> intersection(const Line2& other) const;

    private: // member
        Vector2d _direction;
        Point2d _p0;
    };
}
