#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Default constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    (void)obj;
    // std::cout << "Copy constructor is called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    (void)obj;
    // std::cout << "Copy assignment operator" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "Destructor is called" << std::endl;
    // infile.close();
}

void    BitcoinExchange::badInput()
{
    std::cerr << "Error: bad input => " << line << std::endl;
}

void    BitcoinExchange::checkLeap(int ymd)
{
    if (ymd % 4 == 0)
    {
        //* ila kan divisible b 100, -> not leap ila ida kan divisible b 400
        if (ymd % 100 == 0)
        {
            if (ymd % 400 == 0)
                leapYear = true; //* divisible by 400 → leap
            else
                leapYear = false; //* divisible by 100 but 400 la → not leap
        }
        else
            leapYear = true;       //* divisible by 4 but 100 la → leap
    }
    else
        leapYear = false; //* machi divisible b 4 → not leap
}

bool    BitcoinExchange::checkDay(int ymd)
{
    if (month == 2)
    {
        if (ymd < 1 || (ymd > 28 && leapYear == false))
            return false;
        else if (ymd < 1 || (ymd > 29 && leapYear == true))
            return false;
    }
    else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (ymd < 1 || ymd > 30)
            return false;
    }
    else
    {
        if (ymd < 1 || ymd > 31)
            return false;
    }
    return true;
}


