#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Default constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    // std::cout << "Copy constructor is called" << std::endl;
    this->date = obj.date;
    this->value = obj.value;
    this->dateDB = obj.dateDB;
    this->valueDB = obj.valueDB;
    this->line = obj.line;
    this->num = obj.num;
    this->leapYear = obj.leapYear;
    this->month = obj.month;
    this->inputMap = obj.inputMap;
    this->DBmap = obj.DBmap;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    // std::cout << "assignment operator is called" << std::endl;
    if (this != &obj)
    {
        this->date = obj.date;
        this->value = obj.value;
        this->dateDB = obj.dateDB;
        this->valueDB = obj.valueDB;
        this->line = obj.line;
        this->num = obj.num;
        this->leapYear = obj.leapYear;
        this->month = obj.month;
        this->inputMap = obj.inputMap;
        this->DBmap = obj.DBmap;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "Destructor is called" << std::endl;
}

void    BitcoinExchange::badInput()
{
    std::cerr << "Error: bad input => " << line << std::endl;
}

void    BitcoinExchange::checkLeap(int ymd)
{
    if (ymd % 4 == 0)
    {
        if (ymd % 100 == 0)
        {
            if (ymd % 400 == 0)
                leapYear = true;
            else
                leapYear = false;
        }
        else
            leapYear = true;
    }
    else
        leapYear = false;
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


