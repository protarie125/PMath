#include <iostream>
#include "../PMathCpp/Vector2d.h"
#include "../PMathCpp/Line2.h"

using namespace ahs;

int main()
{
    Point2d p{ 3, 0 };
    Line2 l{ Vector2d::e1(), Point2d{6, 0} };

    std::cout << l.distance(p) << '\n';

    return 0;
}
