#include "Fixed.hpp"

void    Fixed::operator>(const Fixed &obj) const
{
    if (fixedValue > obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

void    Fixed::operator<(const Fixed &obj) const
{
    if (fixedValue < obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

void    Fixed::operator>=(const Fixed &obj) const
{
    if (fixedValue >= obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

void    Fixed::operator<=(const Fixed &obj) const
{
    if (fixedValue <= obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

void    Fixed::operator==(const Fixed &obj) const
{
    if (fixedValue == obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

void    Fixed::operator!=(const Fixed &obj) const
{
    if (fixedValue != obj.getRawBits())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return (this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator++()
{
    this->fixedValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    ++this->fixedValue;
    return (*this);
}

Fixed Fixed::operator--()
{
    this->fixedValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    --this->fixedValue;
    return (*this);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1.toFloat() < num2.toFloat())
        return (num1);
    return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
    if (num1.toFloat() < num2.toFloat())
        return (num1);
    return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
    if (num1.toFloat() > num2.toFloat())
        return (num1);
    return (num2);
}

Fixed::Fixed(const int num)
{
    // std::cout << "Int constructor called" << std::endl;
    fixedValue = num << fractionalBits;
}

Fixed::Fixed(const float num)
{
    // std::cout << "Float constructor called" << std::endl;
    fixedValue = roundf(num * (1 << fractionalBits));
}

Fixed::Fixed() : fixedValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &assign)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = assign;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    fixedValue = obj.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    fixedValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)fixedValue / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (fixedValue >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}
