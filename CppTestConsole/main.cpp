#include <iostream>
#include "../PMathCpp/Vector2d.h"

using namespace ahs;

int main()
{
    Vector2d v{ 3, 4 };
    std::cout << v.to_string() << '\n';

    constexpr auto pi = 3.14159265358979323846;
    v = v.rotate(pi / 2);
    std::cout << v.to_string() << '\n';

    v = v.normalize();
    std::cout << v.to_string() << '\n';

    return 0;
}
