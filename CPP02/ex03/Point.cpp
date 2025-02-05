#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    // std::cout << "default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    // std::cout << "constructor called" << std::endl;
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
    // std::cout << "copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &obj)
{
    // std::cout << "copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        delete this;
        new (this) Point(obj);
    }
    return (*this);
}

Point::~Point()
{
    // std::cout << "destructor called" << std::endl;
}

Fixed Point::xAxis() const
{
    return (this->x);
}

Fixed Point::yAxis() const
{
    return (this->y);
}