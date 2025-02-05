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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif