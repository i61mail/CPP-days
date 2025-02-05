#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private :
        Fixed const x;
        Fixed const y;
    public :
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator=(const Point &obj);
        ~Point();
        Fixed xAxis() const;
        Fixed yAxis() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif