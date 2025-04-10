#ifndef CAST_HPP
#define CAST_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();

    public :
        enum Type
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID,
            LITERAL
        };
        
        static void convert(const std::string &literal);
};

#endif