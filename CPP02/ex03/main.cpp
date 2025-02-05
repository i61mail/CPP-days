#include "Point.hpp"

int main()
{
    Point a(1, 1);
    Point b(2, 2);
    Point c(3, 3);
    Point point(3, 3);

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle" << std::endl;
    else
        std::cout << "The point is outside the triangle" << std::endl;
    return (0);
}