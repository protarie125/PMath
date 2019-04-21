#include <iostream>
#include "../PMathCpp/Vector2d.h"
#include "../PMathCpp/Point2d.h"
#include "../PMathCpp/Line2.h"

using namespace ahs;

int main()
{
    Line2 l1 = Line2{ Vector2d::e0(), Point2d{0,3} };
    Line2 l2 = Line2{ Vector2d::e1(), Point2d{2, 0} };

    auto i = l1.intersection(l2);

    if (i != nullptr)
    {
        std::cout << i->to_string() << '\n';
    }
    else
    {
        std::cout << "l1과 l2는 교점을 갖지 않습니다.\n";
    }

    return 0;
}
