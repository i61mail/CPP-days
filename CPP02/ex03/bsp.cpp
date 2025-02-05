#include "Point.hpp"


Fixed calculateArea(Point const a, Point const b, Point const c)
{
    Fixed areaPoint1 = a.xAxis() * (b.yAxis() - c.yAxis());
    Fixed areaPoint2 = b.xAxis() * (c.yAxis() - a.yAxis());
    Fixed areaPoint3 = c.xAxis() * (a.yAxis() - b.yAxis());
    
    Fixed absArea = (areaPoint1 + areaPoint2 + areaPoint3) / Fixed(2.0f);
    if (absArea.getRawBits() < 0)
        absArea = absArea * Fixed(-1.0f);
    return (absArea);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed mainArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    Fixed sumArea = area1 + area2 + area3;
    if (mainArea.getRawBits() == sumArea.getRawBits())
        return (true);
    return (false);
}