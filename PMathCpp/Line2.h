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
        직선을 'ax + by + c = 0'형으로 변형했을 때의 계수 a, b, c를 반환합니다.
        */
        virtual std::array<Pdouble, 3> make_abc() const;
        /*
        직선과 한 점 사이의 거리를 반환합니다.
        */
        virtual Pdouble distance(const Point2d& p) const;
        /*
        두 직선이 평행한지 조사합니다.
        */
        virtual bool is_parallel(const Line2& other) const;
        /*
        두 직선의 교점을 반환합니다. 교점이 없다면 nullptr를 반환합니다.
        */
        virtual std::unique_ptr<Point2d> intersection(const Line2& other) const;

    private: // member
        Vector2d _direction;
        Point2d _p0;
    };
}
