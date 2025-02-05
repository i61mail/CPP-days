#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int fixedValue;
        static const int fractionalBits = 8;
    public :
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &assign);
        ~Fixed();
        Fixed &operator=(const Fixed &obj);


        void operator>(const Fixed &obj) const;
        void operator<(const Fixed &obj) const;
        void operator>=(const Fixed &obj) const;
        void operator<=(const Fixed &obj) const;
        void operator==(const Fixed &obj) const;
        void operator!=(const Fixed &obj) const;

        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;

        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &num1, Fixed &num2);
        static const Fixed &min(const Fixed &num1, const Fixed &num2);
        static Fixed &max(Fixed &num1, Fixed &num2);
        static const Fixed &max(const Fixed &num1, const Fixed &num2);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif